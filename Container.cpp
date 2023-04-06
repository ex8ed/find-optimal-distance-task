#include "Container.h"
#include <cmath>

Container::Container() {}

Container::Container(const Container& prototype){
    for (auto &i: prototype) append(i);
}

Container::~Container() {
    clean();
}

Container::Iterator Container::begin() const {
    return Iterator(head_);
}

Container::Iterator Container::end() const {
    return Iterator(nullptr);
}

void Container::append(const Turn &cmd_) {
    auto i = begin();
    // проверка на наличие
    if (i != end()) {
        for (; i.notLast(); ++i);
        i.getCurrent()->next_p = new queue{.cmd = cmd_, .next_p = nullptr};
        length_ += 1;
    } else {
        head_ = new queue{.cmd = cmd_, .next_p = nullptr};
        length_ += 1;
    }
}

Turn Container::pop() {
    length_ -= 1;
    Turn ret_cmd = *begin();
    queue *ret_struct = begin().getCurrent();
    head_ = ret_struct->next_p;
    delete ret_struct;
    return ret_cmd;

}

void Container::clean() {
    while (begin() != end()) {
        this->pop();
    }
}

int Container::getLength() const {
    return length_;
}

Container::coordinates * Container::getCoordinates() {
    int p_time = 0;
    auto* cord = new coordinates;

    for (auto & i : *this){
        cord->x_ += (float) (i.speed() * (i.time() - p_time)) * cos(i.angle());
        cord->y_ += (float) (i.speed() * (i.time() - p_time)) * sin(i.angle());
        p_time = i.time();
    }
    return cord;
}

void Container::writeToFile(std::ofstream & f_out) const {
    for (auto & i : *this){

    }
    f_out.close();
}

void Container::readFromFile(std::ifstream & f_in) const {

}

// Iterator implementation

Container::Iterator::Iterator(Container::queue *element) : current(element) {}

Container::Iterator::Iterator(const Container::Iterator &prototype) {
    current = prototype.current;
}

Container::Iterator &Container::Iterator::operator++() {
    current = current->next_p;
    return *this;
}

bool Container::Iterator::operator!=(const Container::Iterator &i) {
    if (current == i.current)
        return false;
    else
        return true;
}

bool Container::Iterator::operator==(const Container::Iterator &i) {
    if (current == i.current)
        return true;
    else
        return false;
}

Turn &Container::Iterator::operator*() const {
    return current->cmd;
}

Turn *Container::Iterator::operator->() const {
    return &current->cmd;
}

Container::queue *Container::Iterator::getCurrent() {
    return current;
}

bool Container::Iterator::notLast() {
    if (current->next_p == nullptr)
        return false;
    else
        return true;
}

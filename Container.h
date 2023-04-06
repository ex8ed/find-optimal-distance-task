#ifndef LAB_CONTAINER_H
#define LAB_CONTAINER_H

#include "Command.h"
#include <fstream>

class Container {
public:
    // Queue
    struct queue {
        Turn cmd;
        queue *next_p;
    };
    struct coordinates{
        float x_ = 0.0;
        float y_ = 0.0;
    };
    // Interface to structure elements
    class Iterator {
    public:
        // Constructor&destructor
        explicit Iterator(queue *element);

        Iterator(const Iterator& prototype);

        ~Iterator() = default;

        // Operators overload
        Iterator &operator++();;

        bool operator!=(const Iterator &i);

        bool operator==(const Iterator &i);

        Turn &operator*() const;;

        Turn *operator->() const;;

        // getter for current element
        queue *getCurrent();

        // Checking for the last possession
        bool notLast();

    private:
        struct queue *current;
    };

    // Container's constructor&destructor
    Container();

    Container(const Container& prototype);

    ~Container();

    // taking iterator to the head
    [[nodiscard]] Iterator begin() const;

    // and to the end
    [[nodiscard]] Iterator end() const;;

    // adding element to the tail
    void append(const Turn &cmd_);

    // Delete and return head of the queue
    Turn pop();

    // delete all
    void clean();

    // get length
    [[nodiscard]] int getLength() const;

    // get coordinates
    coordinates * getCoordinates();

    //file funcs
    void writeToFile(std::ofstream & f_out) const;

    void readFromFile(std::ifstream & f_in) const;

private:
    queue *head_ = nullptr;
    int length_ = 0;
};


#endif //LAB_CONTAINER_H

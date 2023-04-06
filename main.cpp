#include <iostream>
#include <cassert>
#include "Command.h"
#include "Container.h"

//testing function
void compare_(Container &c1, Container &c2) {
    for (auto i = c1.begin(), j = c2.begin(); i != c1.end() && j != c2.end(); ++i, ++j) {
        assert(*i == *j);
    }
}


//USE CONSTANTS FOR TESTS
int main() {
    //List of Base-class tests
    // Constants for testing
    int nil = 0,
            two = 2,
            five = 5,
            six = 6,
            fifteen = 15;

    //default constructor test
    Turn com1;
    assert(com1.time() == nil);
    assert(com1.speed() == nil);

    //init constructor test
    Turn com2;
    com2.set_speed(two);
    com2.set_time(fifteen);
    com2.set_angle(30);
    assert(com2.time() == fifteen);
    assert(com2.speed() == two);

    //copy constructor test
    const Command &com3(com2);
    assert(com3.time() == com2.time());
    assert(com3.speed() == com2.speed());

    //setters test
    Turn com4(0, 0, 0);
    com4.set_time(six);
    com4.set_speed(fifteen);
    com4.set_angle(30);
    assert(com4.time() == six);
    assert(com4.speed() == fifteen);

    // List of container's tests:

    Container c_test_1 = Container();
    Container c_test_2 = Container();
    Container c_test_3 = Container();

    // initialize containers
    for (int i = nil; i < 10; i++) {
        c_test_1.append(Turn(i, (float) i, 0));
        c_test_2.append(com2);
        c_test_3.append(Turn(i, (float) i, 0));
    }

    std::cout << "Length after initializing" << std::endl;
    std::cout << c_test_1.getLength() << std::endl;

    // checking for changes in fields
    int n = 0;
    for (auto i = c_test_1.begin(); i != c_test_1.end(); ++i, ++n)
        assert(i->time() == n && i->speed() == (float) n && i->angle() == 0.0);

    // matching func
    compare_(c_test_1, c_test_3);

    // getting coordinates for all the seq:
    std::cout << "Coordinates in sequence" << std::endl;
    std::cout << c_test_1.getCoordinates()->x_ << " " << c_test_1.getCoordinates()->y_ << std::endl;

    //test use for pop method
    c_test_1.pop();
    Turn result_com = c_test_1.pop();
    std::cout << "Pare of values in the second item" << std::endl;
    std::cout << result_com.time() << ' ' << result_com.speed() << std::endl;
    std::cout << "Current length (two pops)" << std::endl;
    std::cout << c_test_1.getLength() << std::endl;
    c_test_1.clean();
    std::cout << "Current length (cleaned)" << std::endl;
    std::cout << c_test_1.getLength() << std::endl;
    return 0;
}

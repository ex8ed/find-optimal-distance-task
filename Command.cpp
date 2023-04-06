#include "Command.h"

//initializing constructor
Command::Command(int time, float speed) :
        time_(time), speed_(speed) {}

//default constructor:
Command::Command() : time_(0), speed_(0.0) {}

//copy constructor
Command::Command(const Command &com) : time_(com.time_), speed_(com.speed_) {}

//destructor
Command::~Command() {}

//speed getter
float Command::speed() const {
    return speed_;
}

//speed setter
void Command::set_speed(float speed) {
    speed_ = speed;
}

//time getter
int Command::time() const {
    return time_;
}

//time setter
void Command::set_time(int time) {
    time_ = time;
}

bool Command::operator==(const Command & C) const {
    if (C.time_ == time_ && C.speed_ == speed_)
        return true;
    else
        return false;
}

// TURN

Turn::Turn(){
    angle_ = 0.0;
    set_time(0);
    set_speed(0);
}

Turn::Turn(int time, float speed, double angle){
    set_time(time);
    set_speed(speed);
    set_angle(angle);
}

Turn::Turn(const Turn &turn){
    angle_ = turn.angle_;
    set_time(turn.time());
    set_speed(turn.speed());
}

Turn::~Turn() {}

double Turn::angle() const {
    return angle_;
}

void Turn::set_angle(double angle) {
    angle_ = angle;
}

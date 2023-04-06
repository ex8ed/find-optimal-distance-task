#ifndef LAB_COMMAND_H_
#define LAB_COMMAND_H_


class Command {
public:
    //initializing constructor
    Command(int time, float speed);

    //default constructor:
    Command();

    //copy constructor
    Command(const Command &com);

    //destructor
    ~Command();

    // setters and getters for values
    [[nodiscard]] float speed() const;

    void set_speed(float speed);

    [[nodiscard]] int time() const;

    void set_time(int time);

    bool operator==(const Command& C) const;

private:
    int time_;    // seconds after the beginning
    float speed_; // m/s
};

class Turn: public Command {
public:
    // default constructor
    Turn();
    // initializing constructor
    Turn(int time, float speed, double angle);
    // copy
    Turn(const Turn &turn);
    // default destructor
    ~Turn();

    // angle getter
    [[nodiscard]] double angle() const;
    // angle setter
    void set_angle(double angle);

private:
    double angle_;
};

#endif //LAB_COMMAND_H_

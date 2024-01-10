// OOP Workshop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
class Ball {
private:
    float x, y, xDelta, yDelta;
    int radius;
public:
    Ball() {
        x = y = xDelta = yDelta = radius = 0;
    }
    Ball(float x, float y, int radius, float xDelta, float yDelta) {
        this->x = x;
        this->y = y;
        this->radius = radius;
        this->xDelta = xDelta;
        this->yDelta = yDelta;
    }
    // setter
    void setX(float x) {
        this->x = x;
    }
    void setY(float y) {
        this->y = y;
    }
    void setXDelte(float xDelta)
    {
        this->xDelta = xDelta;
    }
    void setYDelta(float yDelta) {
        this->yDelta = yDelta;
    }
    void setRadius(int radius) {
        this->radius = radius;
    }

    // getter

    float getX() {
        return x;
    }
    float getY() {
        return y;
    }
    float getXDelta() {
        return xDelta;
    }
    float getYDelta() {
        return yDelta;
    }
    int getRadius() {
        return radius;
    }

    // methods
    void move() {
        x += xDelta;
        y += yDelta;
    }

    void reflectHorizontal() {
        xDelta = -xDelta;
    }
    void reflectVertical() {
        yDelta = -yDelta;
    }

    string toString() {
        string s = "Ball[(" + to_string(x) + "," + to_string(y) + "),speed=(" + to_string(xDelta) + "," + to_string(yDelta) + ")]";
        return s;
    }


};



int main()
{

    Ball b(0,0,10,5,5);

    cout << b.toString() << endl;
    b.move();
    cout << b.toString() << endl;
    
}


class Employee {
private:
    int id, age;
    string name, email;
    double salary;
public:
    Employee() {
        id = age = salary = 0;
    }

    Employee(int id, int age, string name, string email, double salary) {
        this->id = id;
        this->age = age;
        this->name = name;
        this->email = email;
        this->salary = salary;
    }

    // setter
    void setId(int id) {
        this->id = id;
    }
    void setAge(int age) {
        this->age = age;
    }
    void setName(string name) {
        this->name = name;
    }
    void setEmail(string email) {
        this->email = email;
    }
    void setSalary(double salary) {
        this->salary = salary;
    }


    // getter
    // Task // 

    double getSalary() {
        return salary;
    }

    virtual void displayInfo() {
        cout << "Id : " << id << endl;
        cout << "Name : " << name << endl;
        cout << "Email : " << email << endl;
        cout << "Age : " << age << endl;
    }
    virtual double calculateSalary() = 0;

};

class Manager : public Employee {
private:
    double bounce;
public:
    Manager() : Employee() {
        bounce = 0;
    }
    Manager(int id, int age, string name, string email, double salary, double bounce) : Employee(id, age, name, email, salary) {
        this->bounce = bounce;
    }

    void setBounce(double bounce) {
        this->bounce = bounce;
    }
    double getBounce() {
        return bounce;
    }

    double calculateSalary() {
        return getSalary() + bounce;
    }

    void displayInfo() {
        cout << "Manager : \n";
        Employee::displayInfo();
        cout << "Salary: " << calculateSalary() << endl;
    }
};

class Engineer : public Employee {
private:
    int projectCount;
public:
    Engineer() : Employee() {
        projectCount = 0;
    }
    Engineer(int id, int age, string name, string email, double salary, int projectCount) : Employee(id, age, name, email, salary) {
        this->projectCount = projectCount;
    }

    void setProjectCount(int projectCount) {
        this->projectCount = projectCount;
    }

    int getProjectCount() {
        return projectCount;
    }

    double calculateSalary() {
        return getSalary() + (projectCount * 1000);
    }

    void displayInfo() {
        cout << "Engineer : \n";

        Employee::displayInfo();
        cout << "Salary: " << calculateSalary() << endl;
    }

};

int main() {

   /* Employee e;
    e.calculateSalary();*/
  /*  Manager m(1,27,"Ahmed","Ahmed@gmail.com",10000,5000);
    m.displayInfo();
    cout << "==============\n";
    Engineer e(100, 30, "Amr", "amr@gmai.com", 10000, 2);
    e.displayInfo();*/


    Employee *e; // has no object
    //e = new Employee();


    e = new Manager();
    e->displayInfo();

    e = new Engineer();
    e->displayInfo();
}


class Duration {
private:
    int hours, minutes, seconds;
public:
    Duration() {
        hours = minutes = seconds = 0;
    }
    Duration(int hours, int minutes, int seconds) {
        this->hours = hours;
        this->seconds = seconds;
        this->minutes = minutes;
    }


    Duration(int milliseconds) {
        // milliseconds -> hours mins , sec
        seconds = milliseconds / 1000;
        hours = seconds / 3600; // 3 
        minutes = seconds % 3600 / 60; // min
        seconds = seconds % 3600 % 60;
    }

    void displayTime() {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
    Duration operator+(Duration d) {
        Duration temp(*this);
        // logic + operator
        //temp.hours = temp.hours + d.hours;
        temp.hours += d.hours;
        temp.minutes += d.minutes;
        temp.seconds += d.seconds;

        // handeling validation time
        // 
        // 0 -> 23
        // 0 -> 59
        // 0 -> 59
        // 22:59:59
        // 1:1:1
        return temp;
    }


    Duration operator-(Duration d) {
        Duration temp(*this);
        // logic + operator
        //temp.hours = temp.hours + d.hours;
        temp.hours -= d.hours;
        temp.minutes -= d.minutes;
        temp.seconds -= d.seconds;

        // handeling validation time
        // 
        // 0 -> 23
        // 0 -> 59
        // 0 -> 59
        // 22:59:59
        // 1:1:1
        return temp;
    }

    bool operator >(Duration d) {
        // hours min sec

        if (this->hours != d.hours) {
            return this->hours > d.hours; // ture or false
        }
        else if (this->minutes != d.minutes) {
            return this->minutes > d.minutes; // 
        }
        else {
            return this->seconds > this->seconds;
        }
    }
    bool operator ==(Duration d) {
        return (this->hours == d.hours) && (this->minutes == d.minutes) && (this->seconds == d.seconds);
    }

    bool operator < (Duration d) {
        return !(*this > d) && !(*this == d);
    }

    // 

    Duration operator ++() {

    }
};

//
//int main() {
//    //Duration d1(1,1,1), d2(1,1,1), d3(d2);
//
//
//    ////d1.displayTime(); // 1:1:1
//    ////d2.displayTime(); // 1:1:1
//    //d3 = d1 + d2;
//    ////d3.displayTime(); // 2:2:2
//    //// 2:2:2          1:1:1
//    ////bool flag = d2 > d3;
//    ////cout << flag;
//
//
//    //// d2 < d1
//
//    //bool flag = d2 == d3;
//    //cout << flag;
//
//    ////d2++;
//
//
//
//   
//}


class NegativeNumberException : public exception {
public:
    virtual char const* what() const
    {
        return "can't calculate sqrt for negative number";
    }
};


// T must be number
template <class T>
class Math {
private:
public:
    // number ^ 2 = 2 ^ 2 = 4
    static T Pow(T number, T power) {
        T res = 1;
        for (int i = 1; i <= power; i++) {
            res *= number;
        }
        return res;
    }
    // -1 -> 1
    // 1  -> 1
    static T Abs(T number) {
        if (number > 0)
            return number;
        return -number;
    }

    static T Sqrt(T number) {
        if (number < 0)
            throw NegativeNumberException();
        return sqrt(number);
    }

};
//
//int main() {
//   
//    //cout << Math<int>::Pow(2, 5) << endl;
//    //cout << Math<int>::Abs(1) << endl; // 1
//    //cout << Math<int>::Abs(-1) << endl; // 1
//    //cout << Math<int>::Sqrt(-9) << endl;
//    int number  = -1;
//    try {
//        cout << Math<int>::Sqrt(number);
//    }
//    catch (exception &e) {
//        cout << e.what() << endl;
//    }
//
//}

class Customer {
private:
    string name, memberType;
    bool member = false;

public:
    Customer() {

    }
    Customer(string name) {
        this->name = name;
    }

    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }

    bool isMember() {
        return member;
    }

    void setMember(bool member) {
        this->member = member;
    }

    void setMemberType(string memberType) {
        this->memberType = memberType;
    }

    string getMemberType() {
        return memberType;
    }

    string toString() {
        //
        return "";
    }


};

class Visit {
private:
    Customer customer;
    string date; // 10/12/2023
    double serviceExpense;
    double productExpense;
public:

    Visit(string name, string date) {
        customer.setName(name);
        this->date = date;
    }

    string getName() {
        return customer.getName();
    }

    // setter getter
    double totalExpense() {

    }
};

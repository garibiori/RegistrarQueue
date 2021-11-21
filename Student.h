/**
 * Student.h creates Student object that can be referrenced using the window class
 * 
 * @author Devin Keller and Ori G
 * @version 1.0
 * @see Student.h
 * 
 */

#ifndef Student_H
#define Student_H
#include <iostream>
using namespace std;

class Student{
    public:
        Student();
        Student(int t);
        ~Student();
        void updateTimeNeeded();
        int getTimeNeeded();
        void setTimeNeeded(int t);
        int getWaitTime();
        void updateWaitTime();

    private:
        int timeNeeded;
        int waitTime;
};

//Default Constructor
Student::Student(){
    timeNeeded = 0;
    waitTime = 0;
}
//Constructor
Student::Student(int t){
    timeNeeded = t;
    waitTime = 0;
}
//Default Destructor
Student::~Student(){

}

//Increments waitTime +1
void Student::updateWaitTime(){
    ++waitTime;
}

//returns waitTime of student
int Student::getWaitTime(){
    return waitTime;
}

//Subtracts wait time students needs to leave window by 1
void Student::updateTimeNeeded(){
    --timeNeeded;
}

//Returns timeNeeded for student to leave window
int Student::getTimeNeeded(){
    return timeNeeded;
}
//Sets the amount of time a student will take at the window
void Student::setTimeNeeded(int t){
    timeNeeded = t;
}

#endif
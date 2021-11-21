/**
 * MyWindow.h creates a window class that represents every window
 * 
 * @author Devin Keller and Ori G
 * @version 1.0
 * @see MyWindow.h
 * 
 */

#ifndef MYWINDOW_H
#define MYWINDOW_H
//Includes Student class
#include "Student.h"
//creates MyWindow Class
class MyWindow{
    public:
        MyWindow();
        MyWindow(Student *s);
        ~MyWindow();
        void updateIdleTime();
        int getIdleTime();
        bool isWindowIdle();
        void setWindowBusy();
        void setWindowIdle();
        int checkTime();
        void updateStudentUse();
        int studentTime();
        Student* getStudent(int num);

    private:
        int idleTime;
        Student *newStudent;
        bool isEmpty;
        //int temp;
};

//Default constructor
MyWindow::MyWindow(){
    //newStudent = new Student();
    idleTime = 0;
    isEmpty = true;
    newStudent = NULL;
}

//Constructor
MyWindow::MyWindow(Student *s){
    newStudent = s;
    idleTime = 0;
    isEmpty = true;
    newStudent = s;
}

//Creates updateIdleTime function 
void MyWindow::updateIdleTime(){
    //increments idleTime by 1
    ++idleTime;
    //temp = idleTime;
}

//Returns idle time of MyWindow
int MyWindow::getIdleTime(){
    return idleTime;
}

//isWindowIdle
bool MyWindow::isWindowIdle(){
    return isEmpty;
}

//Sets Window to busy which makes isEmpty = false
void MyWindow::setWindowBusy(){
    isEmpty = false;
}

//Sets Window to idle which make isEmpty = true
void MyWindow::setWindowIdle(){
    isEmpty = true;
}

//Checks to see how much time student still needs at window
int MyWindow::checkTime(){
    return newStudent->getTimeNeeded();
}

//Runs updateTime Needed and getTimeNeeded functions of student
void MyWindow::updateStudentUse(){
    newStudent ->updateTimeNeeded();
    newStudent->getTimeNeeded();
}
//Returns 0 if getTimeNeeded < 0 or returns time needed for student at window
int MyWindow::studentTime(){
    if(newStudent->getTimeNeeded()<0){
        return 0;
    }
    else{
        return newStudent->getTimeNeeded();
    }
}

//Gets a new student at window
Student* MyWindow::getStudent(int num){
    return newStudent;
}


#endif

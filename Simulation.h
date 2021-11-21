/**
 * Simulation runs a simulation of the Regestration Office 
 * 
 * @author Devin Keller and Ori G
 * @version 1.0
 * @see Simulation.h
 * 
 */

#include <iostream>
#include <fstream>
#include "MyWindows.h"
#include "Student.h"
#include "GenQueue.h"
#include "DoublyLinkedList.h"
//Creates Simulation class
class Simulation
{
public:
    Simulation();
    Simulation(int t);
    ~Simulation();
    void runSimulation();
    void processFile(string input);
    void makeArray();

private:
    int minutes;
    int windows;
    int time;
    int students;
    int worldClock;
    int nextTime;
    int numStuds = 0;
    int studInLine = 0;
    int capacity;
    MyWindow *empty = new MyWindow();
    MyWindow **wind;
    int **emptyArr;
    GenQueue<int> *values;
    GenQueue<int> *tempExit;
    GenQueue<int> *list;
    GenQueue<int> *tempWait;
    int enteredLine;
    int arrVal=0;
    int idle = 0;
    int meanIdleTime;
    int idleOver5=0;
    int longestIdleTime = 0;
    int median;
    //DoublyLinkedList<int> *values;
};
//Default Constructor
Simulation::Simulation()
{
}
//Default Destructor
Simulation::~Simulation()
{
}
//Creates an array of windows
void Simulation::makeArray()
{
    //Creates Queues
    tempExit = new GenQueue<int>;
    tempWait = new GenQueue<int>;
    list = new GenQueue<int>;
    //Creating Windows
    capacity = values->remove();
    wind = new MyWindow *[capacity];
    emptyArr = new int *[capacity];
    for (int i = 0; i < capacity; ++i)
    {
        wind[i] = new MyWindow();
    }
    cout << capacity << " Windows Created" << endl;
}
void Simulation::runSimulation()
{

    //WorldClock
    worldClock = 0;
    //float for sumOfWaitTimes 
    float sumOfWaitTimes = 0.0;
    //float for total amount of students
    float totalStudents = 0.0;
    //int of the longestWaitTime of all the students
    int longestWaitTime = 0;
    int numOfStudentsWaitingOver10 = 0;

    nextTime = values->remove();

    //int count = 0;
    while (values->isEmpty() == 0 && worldClock < 100)
    {
        //World time
        cout << endl;
        cout << "World Clock: " << worldClock << endl;
        //cout<<"i am in the while loop"<<endl;
        //next time student comes is = to queue.pop
        cout << "next time students will show up: " << nextTime << endl;
        //If next time is equal to world clock then add students to line
        if (worldClock == nextTime)
        {
            //displays how many students entered the line
            cout << values->peek() << " students have entered the line" << endl;
            //Adds students to line
            studInLine += values->remove();
            //For every student in line
            for (int x = 0; x < studInLine; ++x)
            {
                //Add values 
                list->insert(values->remove());
                //cout<<"LOOK OVER HERE!!!!!!!!!!!!"<<list->peek()<<endl;
                //Add to new queue 0
                tempWait->insert(worldClock);
                //count += 1;
            }
            //if values is not empty
            if (!values->isEmpty())
            {
                //next time is = to the next value in the values queue
                nextTime = values->remove();
                cout << "Next Time: " << nextTime << endl;
            }
        }
        cout << "Number of Students still waiting in line: " << studInLine << endl<< endl;
        //for every window
        for (int i = 0; i < capacity; ++i)
        {
            //if window is not busy and values is not empty
            if (wind[i]->isWindowIdle() && !values->isEmpty())
            {
                
                cout << "Window " << i << " is empty" << endl;
                //if studens in line is not = 0
                if (studInLine != 0)
                {
                    //Add next value in in values queue to sumOfWaitTimes
                    sumOfWaitTimes += values->peek();
                    //if the next value in values queue is greater than longestWaitTime 
                    if (values->peek() > longestWaitTime)
                    {
                        //Sets longestWaitTime = next value in values queue
                        longestWaitTime = values->peek();
                    }
                    //Checks to see if next value in values queue is greater then 10 then add 1 to numOfStudentsWaitingOver10
                    if (values->peek() > 10)
                    {
                        numOfStudentsWaitingOver10 += 1;
                    }
                    //If values isn't empty
                    if (values->isEmpty() == 0)
                    {
                        //Adds student to empty window
                        wind[i] = new MyWindow(new Student(list->remove()));
                        //insert WorldClock time to tempExit
                        tempExit->insert(worldClock);
                        cout << "student added to window: " << i << " with wait time: " << wind[i]->checkTime() << endl;
                        //Subtracts students In Line by 1 and totalStudents in line by 1
                        studInLine -= 1;
                        totalStudents +=1;
                        //set window busy
                        wind[i]->setWindowBusy();
                        cout << "Students still waiting in line: " << studInLine << endl << endl;
                    }
                }
                else{
                    //cout<<"UPDATING IDLE TIME====="<<endl;
                    //updates windowIdleTime +1
                    wind[i]->updateIdleTime();
                    idle+=1;
                    //if window idle time is greater than 5 then add 1 to idleOver5
                    if(wind[i]->getIdleTime()>5){
                        idleOver5+=1;
                    }
                    //Finds longest window idle time
                    if(wind[i]->getIdleTime()>longestIdleTime){
                        longestIdleTime=wind[i]->getIdleTime();
                    }
                }
            }
            //cout << values->peek() <<endl;
            if (i == capacity - 1 && studInLine != 0)
            {
                //for every window
                for (int j = 0; j < capacity; ++j)
                {
                    //Student time = 0
                    if (wind[j]->studentTime() == 0)
                    {
                        //set Window to Idle
                        wind[j]->setWindowIdle();
                        cout << "Window " << j << " is now empty" << endl;

                        //adds student to line if not empty
                        if (studInLine != 0 && (values->isEmpty() != 1))
                        {
                            //Adds students to Window
                            wind[j] = new MyWindow(new Student(list->remove()));
                            //Adds world clock to tempExit
                            tempExit->insert(worldClock);
        
                            cout << "student added to window: " << j << " with wait time: " << wind[j]->checkTime() << endl;
                            studInLine -= 1;
                            totalStudents +=1;
                            cout << "Students still waiting in line: " << studInLine << endl;
                        }
                    }
                }
            }
        }
        //For every window
        for (int j = 0; j < capacity; ++j)
        {
            //if window is idle run updateStudentUse to update wait time
            if (wind[j]->isWindowIdle() == 0)
            {
                wind[j]->updateStudentUse();
                cout << "this is how much more time student " << j << " still has to spend " << wind[j]->studentTime() << endl;
            }
        }
        worldClock += 1;

    }
    
    sumOfWaitTimes =0;
    longestWaitTime = 0;
    
    //creates queue waitTimes that houses the wait times of each student
    GenQueue<int> *waitTimes= new GenQueue<int>;

    //cout<<"the size is "<<tempExit->getSize()<<endl;
    //Gets median
    int med = tempExit->getSize()/2;
    for(int i = 0; i<100;++i){
        //If queues not empty
        if(!tempWait->isEmpty() && !tempExit->isEmpty()){
            //waitTime is equal to time exited line minus time entered line
            int waitTime = tempExit->remove()-tempWait->remove();
            waitTimes->insert(waitTime);
            //finds longest waitTime
            if (waitTime>longestWaitTime){
                longestWaitTime = waitTime;
            }
            //Finds number of students who had to wait over 10 minutes
            if (waitTime > 10){
                numOfStudentsWaitingOver10 +=1;
            }
            //Finds median
            if(!waitTimes->isEmpty()){
                if(i==med){
                    median = waitTimes->peek();
                }
                sumOfWaitTimes += waitTimes->remove();
            }
            
        }
    }
    /**
    for(int i = 0; i<capacity;++i){
        cout<<"IDLE TIME "<<wind[i]->getIdleTime()<<endl;
    }*/
    //cout<<idle<<endl;
    meanIdleTime = idle/capacity;

    cout << endl;
    //Prints out Data of student to terminal
    cout << "Data: " << endl<< endl;
    cout << "Sum of wait time: " << sumOfWaitTimes << endl;
    cout << "Number of students: " << totalStudents << endl;
    float meanOfWaitTime = sumOfWaitTimes / totalStudents;
    cout << "The mean student wait time: " << meanOfWaitTime << endl;
    cout << "The median student wait time: " <<median<< endl;
    cout << "The longest student wait time: " << longestWaitTime << endl;
    cout << "Number of students waiting over 10 minutes: " << numOfStudentsWaitingOver10 << endl;
    cout << "The mean window idle time: " << meanIdleTime<<endl;
    cout << "The longest window idle time: " <<longestIdleTime<<endl;
    cout << "Number of windows idle time over 5 minutes: " <<idleOver5<< endl;
    cout << endl
         << endl;
    delete[] wind;
}
void Simulation::processFile(string file) //takes in a file from the command line and sends data to genqueue
{
    char data[500];
    values = new GenQueue<int>;
    // open and read the input file
    ifstream infile;
    infile.open(file);
    int count = 0;
    int val;

    string sentence;
    string inputLine = "";

    while (getline(infile, sentence))
    {
        val = stoi(sentence);
        values->insert(val);
        inputLine += sentence;
        inputLine += "\n";
    }
    makeArray();
    runSimulation();

    //cout << "Reading from the file..." << endl;
    infile >> inputLine;

    //close the inputted file.
    infile.close();

}
/**
 * GenQueue is the template file for the doublylinkedlist Queue
 * 
 * @author Devin Keller and Ori G
 * @version 1.0
 * @see GenQueue.h 
 * 
 */

#ifndef GENQUEUE_H
#define GENQUEUE_H
#include <iostream>
#include <exception>
#include "ListInterface.h"
using namespace std;
template <class T>
class GenQueue{
  public:
    GenQueue(); // defualt constructor
    GenQueue(unsigned int maxSize); // overloaded construcotr
    ~GenQueue(); // destructor
    // core functions
    void insert(T data); //aka
    T remove(); // aka dequeue
    // aux/helper functions
    T peek();
    unsigned int getSize();
    bool isFull();
    bool isEmpty();
    void printArray();
  private:
    ListInterface<T> *list;
    T *myQueue;
    unsigned int mSize;
    int front;
    int rear;
    unsigned int numElements;
};
template <class T>
GenQueue<T>::GenQueue(){
  mSize = 128;
  myQueue = new T[mSize];
  front = 0;
  rear = 0;
  numElements = 0;
  list = new ListInterface<T>();
}
template <class T>
GenQueue<T>::GenQueue(unsigned int maxSize){
  mSize = maxSize;
  myQueue = new T[mSize];
  front = 0;
  rear = 0;
  numElements = 0;
  list = new ListInterface<T>();
}
template <class T>
GenQueue<T>::~GenQueue(){
  cout << "queue destructed" << endl;
  delete [] myQueue;
}
template <class T>
void GenQueue<T>::insert(T data){
  if (isFull()){
    throw runtime_error("queue is full");
  }
  list->insertBack(data);
  rear %= mSize;
  ++numElements;
}
template <class T>
T GenQueue<T>::remove(){
  if (isEmpty()){
    throw runtime_error("queue is empty");
  }
  --numElements;
  front %= mSize;
  return list->removeFront();
}
template <class T>
T GenQueue<T>::peek(){
  if(isEmpty()){
    throw runtime_error("queue is empty");
  }
  T _data = list->removeFront();
  list->insertFront(_data);
  return _data;
}
template <class T>
unsigned int GenQueue<T>::getSize(){
  return numElements;
}
template <class T>
bool GenQueue<T>::isFull(){
  return (numElements == mSize);
}
template <class T>
bool GenQueue<T>::isEmpty(){
  return (numElements == 0);
}
#endif
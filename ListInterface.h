/**
 * Listinterface Template file
 * 
 * @author Devin Keller and Ori G
 * @version 1.0
 * @see ListInterface.h
 * 
 */

#ifndef LISTINTERFACE_H
#define LISTINTERFACE_H

#include "DoublyLinkedList.h"

template <class T> class ListInterface{
public:
    ListInterface();
    ~ListInterface();
    void insertFront(T d);
    void insertBack(T d);
    T removeFront();
    T removeBack();
    T removeNode(T value);
    T find(T value);
    bool isEmpty();
    unsigned int getSize();
private:
    DoublyLinkedList<T> *list;
};
template <class T>
ListInterface<T>::ListInterface(){
    list = new DoublyLinkedList<T>();
}
template <class T>
ListInterface<T>::~ListInterface(){
    delete list;
}
template <class T>
void ListInterface<T>::insertFront(T d){
    list->insertFront(d);
}
template <class T>
void ListInterface<T>::insertBack(T d){
    list->insertBack(d);
}
template <class T>
T ListInterface<T>::removeFront(){
    return list->removeFront();
}
template <class T>
T ListInterface<T>::removeBack(){
    return list->removeBack();
}
template <class T>
T ListInterface<T>::removeNode(T d){
    return list->removeNode(d);
}
template <class T>
T ListInterface<T>::find(T d){
    return list->find(d);
}
template <class T>
bool ListInterface<T>::isEmpty(){
    return list->isEmpty();
}
template <class T>
unsigned int ListInterface<T>::getSize(){
    return list->getSize();
}
#endif
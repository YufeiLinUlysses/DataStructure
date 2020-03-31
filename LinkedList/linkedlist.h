#ifndef LinkedLIST_H
#define LinkedLIST_H

template <class Type>
struct Node
{
    Type data;
    Node *next;
    Node(Type d, Node *n) : data(d), next(n) {}
};

template <class Type>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const Type &d);
    virtual ~LinkedList();
    void printOut();
    Node<Type> *firstElement();
    Node<Type> *lastElement();
    int length();
    bool isEmpty();
    void insertAtHead(const Type &d);
    void insertAtTail(const Type &d);
    void removeFromHead();
    void removeFromTail();
    Type *toArray();
    bool search(const Type &d); 
    // void deleteData(char, bool);

private:
    Node<Type> *head, *tail;
    int size;
};

#include "linkedlist.cpp"
#endif
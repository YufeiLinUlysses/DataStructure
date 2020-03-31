#include "linkedlist.h"
#include <string.h>
#include <iostream>

using namespace std;

//Initializes a linked list without any input
template <class Type>
LinkedList<Type>::LinkedList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

//Initializes a linked list with an input
template <class Type>
LinkedList<Type>::LinkedList(const Type &d)
{
    head = new Node<Type>(d, NULL);
    tail = head;
    size = 1;
}

//Print out an entire linked list
template <class Type>
void LinkedList<Type>::printOut()
{
    Node<Type> *tmp = head;
    do
    {
        cout << tmp->data;
        tmp = tmp->next;
    } while (tmp != NULL);
    cout << endl;
}

//Get the head of the linked list
template <class Type>
Node<Type> *LinkedList<Type>::firstElement()
{
    return head;
}

//Get the tail of the linked list
template <class Type>
Node<Type> *LinkedList<Type>::lastElement()
{
    return tail;
}

//Get the length of the linked list
template <class Type>
int LinkedList<Type>::length()
{
    return size;
}

//Delete the entire linked list
template <class Type>
LinkedList<Type>::~LinkedList()
{
    Node<Type> *tmp = this->head;
    Node<Type> *temp;
    while (tmp)
    {
        temp = tmp->next;
        delete tmp;
        tmp = temp;
    }
    tmp = temp = NULL;
}

//Check whether the linked list is empty
template <class Type>
bool LinkedList<Type>::isEmpty()
{
    return (this->size == 0);
}

//Insert a data at the beginning of the list
template <class Type>
void LinkedList<Type>::insertAtHead(const Type &d)
{
    Node<Type> *n = head;
    Node<Type> *newNode = new Node<Type>(d, n);
    head = newNode;
    size++;
}

//Insert a data at the end of the list
template <class Type>
void LinkedList<Type>::insertAtTail(const Type &d)
{
    Node<Type> *newNode = new Node<Type>(d, NULL);
    if (size == 0)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

//Remove data from the beginning of the list
template <class Type>
void LinkedList<Type>::removeFromHead()
{
    if (size == 0)
    {
        return;
    }
    else if (size == 1)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = head->next;
    }
    size--;
}

//Remove data from the end of the list
template <class Type>
void LinkedList<Type>::removeFromTail()
{
    if (size == 0)
    {
        return;
    }
    else if (size == 1)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        Node<Type> *tmp = head;
        do
        {
            tmp = tmp->next;
        } while (tmp->next != tail);
        tmp->next = NULL;
        tail = tmp;
    }
    size--;
}

//Convert the linked list to array
template <class Type>
Type *LinkedList<Type>::toArray()
{
    int i = 0;
    static char ans[10000];
    Node<Type> *tmp = head;
    do
    {
        ans[i] = tmp->data;
        tmp = tmp->next;
        i++;
    } while (tmp != NULL);
    return ans;
}

//Search for the first instance of element in the list
template <class Type>
bool LinkedList<Type>::search(const Type &d)
{
    int counter = 0;
    Node<Type> *tmp = head;
    while (tmp->next != head)
    {
        if (tmp->data == d)
            counter++;
        tmp = tmp->next;
    }

    if (counter > 0)
    {
        cout << "'" << search << "' was found " << counter << " time(s)" << endl;
        return true;
    }
    else
    {
        cout << "'" << search << "' was not found" << endl;
        return false;
    }
}

// void LinkedList::deleteData(char search, bool all) // If true, it will delete all nodes with the same search
// {                                                  // If false, it will delete the first Node only
//     Node *tmp = head;
//     while (tmp)
//     {
//         if (tmp->data == search)
//         {
//             cout << "Deleting " << search << endl;
//             tmp->prev->next = tmp->next;
//             tmp->next->prev = tmp->prev;
//             if (false)
//                 return;
//         }
//         tmp = tmp->next;
//     }
// }
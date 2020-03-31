#include <string.h>
#include <iostream>
#include "./LinkedList/linkedlist.h"

using namespace std;

int main(int argc, char* argv[])
{
    char s[]="abcd";
    char *ans;
    LinkedList<char> *list; // ptr to head of list
    Node<char> *head, *tail; // ptr to current node of the list
    bool test;
    int length;

    // call constructor and initialize first Node
    list = new LinkedList<char>(s[0]);

    for(size_t i=1; i < strlen(s); i++) // create the rest of the linked list
        list->insertAtTail(s[i]);

    list -> removeFromHead();
    head = list->firstElement();
    tail=list->lastElement();
    test = head==tail;
    length= list->length();

    ans = list->toArray();

    list->printOut();
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
    cout<<test<<endl;
    cout<<length<<endl;
    for (int i=0;i<length;i++){
        cout<<*(ans+i)<<endl;
    }
    return 0;
}
// ECE 209, Spring 2019
// Homework 2, Problem 2

// LinkedList class

// main function to demonstrate class

#include "Item.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class ListNode{
private:
    Item item;
    ListNode * next;
public:
    ListNode(Item a) {
        item = a;
        next = nullptr;
    }
    ListNode *getNext() { return next; }
    void setNext(ListNode *ptr) { next = ptr; }
    Item getItem() { return item; }
};

class LinkedList{
private:
    ListNode* head;
    ListNode* tail;
public:
    LinkedList();
    ~LinkedList();
    LinkedList (const LinkedList &other)
    {
        ListNode *temp = other.head;
        while(temp!=nullptr)
        {
          append(temp->getItem());
          temp = temp->getNext();
        }
    }
    int length();
    void append(Item a);
    bool remove(Item &a);
    bool empty();
    bool insert(const Item &a, int position);
};

LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
}

bool LinkedList::empty()
{
    return head == nullptr;
}

LinkedList::~LinkedList(){
    Item t;
    while (remove(t));
}

void LinkedList::append(Item a){
    auto node = new ListNode(a);
    if (head == nullptr) {
        head = node;
        tail = node;
    }
    else {
        tail->setNext(node);
        tail = node;
    }
}

bool LinkedList::remove(Item& a) {
    if(!empty()){
        a = head->getItem();
        auto tmp = head->getNext();
        delete head;
        head = tmp;
        if (head == nullptr){
            tail = nullptr;
        }
        return true;
    }
    else{
        return false;
    }
}

int LinkedList::length(){
    int count = 0;
    ListNode *p = head;
    while(p!=nullptr){
        ++count;
        p = p->getNext();
    }
    return count;
}

bool LinkedList::insert(const Item &a, int position){
    ListNode *prev = head;
    ListNode *current = head->getNext();

    if(head == nullptr){
        head = new ListNode(a);
        tail = new ListNode(a);
    }
    else if(position == 0){
        ListNode *temp = head;
        head = new ListNode(a);
        head->setNext(temp);
    }
    else{
        int current_position = 1;
        while(current_position < position-1){
            prev = current;
            current = current->getNext();
        }
        ListNode *temp2 = new ListNode(a);
        prev->setNext(temp2);
        temp2->setNext(current);
        return true;

    }
return false;
}


//int main() {
//    LinkedList *l = new LinkedList;
//    l->append(Item(5, "one"));
//    l->append(Item(5, "two"));
//    l->append(Item(5, "three"));
//    l->append(Item(5, "four"));
//    l->append(Item(5, "five"));
//
//    cout << endl << l->length() << endl << endl;
//
//    l->insert(Item(5, "six"), 2);
//
//    while(!l->empty())
//    {
//        Item copy;
//        l->remove(copy);
//
//        printf("Next thing removed: %s\n",copy.getValue());
//    }
//    cout << endl << l->empty() << endl;
//    return 0;
//}
// ECE 209, Spring 2019
// Homework 2, Problem 3

// ArrayList class

// main function to demonstrate the class
#include "Item.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "LinkedList.cpp"


using namespace std;


class ArrayList{
private:
    int data;
    int counter;
    int arraySize;
    Item *array;
public:
    ArrayList(int initialSize = 3);
    int length();
    void append(Item a);
    bool remove(Item &a);
    bool empty();
    bool insert(const Item &a, int position);
    ~ArrayList();
};

ArrayList::ArrayList(int initalSize){
    arraySize = initalSize;
    array = new Item[arraySize];
    counter = 0;
}

void ArrayList::append(Item a) {
    if(arraySize < counter + 1) {
        int arraySize2 = arraySize + 1;
        Item *newArray = new Item[arraySize2];
        int i = 0;
        while(i<arraySize){
            newArray[i] = array[i];
            i++;
        }
        arraySize = arraySize2;
        delete[] array;
        array = newArray;
    }
    array[counter] = a;
    ++counter;
}

int ArrayList::length(){
    return counter;
}

bool ArrayList::remove(Item &a){
    for(int i = 0; i<counter; i++){
        array[i] = array[i+1];
    }
    array[counter-1].setItem(0, nullptr);
    counter -= 1;
    return true;
}

ArrayList::~ArrayList(){
    delete[] array;
}

bool ArrayList::insert(const Item &a, int position) {
    if (array[position].getValue() != nullptr) {
        array[position] = a;
        return true;
    }
    else{
        return false;
    }
}

bool ArrayList::empty(){
    if(counter==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}




int main() {
    LinkedList *l = new LinkedList;
    l->append(Item(5, "one"));
    l->append(Item(5, "two"));
    l->append(Item(5, "three"));
    l->append(Item(5, "four"));
    l->append(Item(5, "five"));

    cout << endl << l->length() << endl << endl;

    l->insert(Item(5, "six"), 2);

    while(!l->empty())
    {
        Item copy;
        l->remove(copy);

        printf("Next thing removed: %s\n",copy.getValue());
    }
    cout << endl << l->empty() << endl;
    return 0;
}

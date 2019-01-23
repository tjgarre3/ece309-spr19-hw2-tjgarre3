// ECE 309 - Spring 2019
// Homework 2, problem 1

#ifndef HW2_ITEM_H
#define HW2_ITEM_H


class Item {
private:
    int key;
    const char *value;

public:
    Item() {key = 0; value = "0";}
    Item(int key, const char *value){
        this->key = key;
        this->value = value;
    }
    int getKey()
    {
        return key;
    }
    const char *getValue()
    {
        return value;
    }
    void setItem(int k, const char* val)
    {
        this->key = k;
        this->value = val;
    }
    Item(const Item &item)
    {
        key = item.key;
        value = item.value;
    }
};


#endif //HW2_ITEM_H

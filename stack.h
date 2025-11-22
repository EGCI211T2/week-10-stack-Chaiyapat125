#ifndef stack_h
#define stack_h

#include <iostream>
#include "node.h"
using namespace std;

class Stack {
    NodePtr top;
    int size;
public:
    void push(char x);
    char pop();     
    Stack();
    ~Stack();
    bool isEmpty();
};

Stack::Stack() {
    top = NULL;
    size = 0;      

Stack::~Stack() {

    while (top != NULL) {
        NodePtr t = top;
        top = top->get_next();
        delete t;
    }
    size = 0;
}

void Stack::push(char x) {
    NodePtr new_node = new NODE(x);
    if (new_node != NULL) {
        new_node->set_next(top);   
        top = new_node;            
        size++;
    }
}

char Stack::pop() {
    if (top == NULL) {
        cout << "Empty ";
        return '\0';            
    }

    NodePtr t = top;
    char value = t->get_value();
    top = top->get_next();
    delete t;
    size--;

 
    cout << value << " ";

    return value;
}

bool Stack::isEmpty() {
    return (top == NULL);
}

#endif

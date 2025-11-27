#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

class Queue {
    NodePtr head;
    NodePtr tail;
    int size;

public:
    Queue() : head(nullptr), tail(nullptr), size(0) {}

    ~Queue() {
        while (!isEmpty()) dequeue();
    }

    bool isEmpty() const { return size == 0; }
    int getSize()  const { return size; }

    void enqueue(int x) {
        NodePtr n = new NODE(x);

        if (!head) {
            head = tail = n;
        } else {
            tail->set_next(n);
            tail = n;
        }
        size++;
    }

    int dequeue() {
        if (!head) return -1;

        NodePtr t = head;
        int val = t->get_value();

        head = head->get_next();
        if (!head) tail = nullptr;

        delete t;
        size--;
        return val;
    }
};

#endif

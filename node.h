#ifndef NODE_H
#define NODE_H

class NODE {
    int data;
    NODE* next;

public:
    explicit NODE(int v) : data(v), next(nullptr) {}

    void set_next(NODE* p) { 
        next = p; }

    NODE* get_next() const { 
        return next; }

    int get_value() const  { 
        return data; }
};

typedef NODE* NodePtr;

#endif

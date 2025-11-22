#ifndef node_h
#define node_h

class NODE {
    char data;
    NODE *nextPtr;
public:
    NODE(char);
    ~NODE();
    void set_next(NODE*);
    NODE* get_next();
    char get_value();
};

typedef NODE* NodePtr;

NODE::NODE(char x) {
    data = x;
    nextPtr = NULL;
}

NODE* NODE::get_next() {
    return nextPtr;
}

char NODE::get_value() {
    return data;
}

void NODE::set_next(NODE *t) {
    nextPtr = t;
}

NODE::~NODE() {
   
}

#endif

#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class node{
public:
    node();
    ~node();
    void insert(int a);
    void print();
    bool exists(int a);
    void remove(int a);
    void del();
private:
    node* next;
    int data;
    bool b;
};

#endif // NODE_H_INCLUDED

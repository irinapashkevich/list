#include <iostream>

using namespace std;

class Container
{
public:
    // Виртуальные методы, должны быть реализованы вашим контейнером
    virtual void insert(int value) = 0;
    virtual bool exists(int value) = 0;
    virtual void remove(int value) = 0;

    // И этот тоже, хотя к нему потом ещё вернёмся
    virtual void print() = 0;

    // Виртуальный деструктор (пока просто поверьте, что он нужен)
    virtual ~Container() { };
};

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

class list: public Container{
public:
    list();
    ~list();
    void insert(int a);
    void print();
    bool exists(int a);
    void remove(int a);
    void del();
private:
    node* root;
    int data;
    bool b;
};

node::node()
{
    this->next=NULL;
    this->data=0;
    this->b=false;
};

node::~node()
{
}

void node::del()
{
    if (this->next!=NULL)
    {
        this->next->del();
        this->next=NULL;
    }
}

void node::insert(int a)
{
    if(this->b)
    {
        if (this->next==NULL)
            this->next=new node();
        this->next->insert(a);
    }
    else
    {
        this->data=a;
        this->b=true;
    }
};

void node::print()
{
    cout<<this->data<<" ";
    if (this->next!=NULL)
        this->next->print();
    else
        cout<<endl;
}

bool node::exists(int a)
{
    if (this->data==a)
        return true;
    if (this->next==NULL)
        return false;
    else
        return (this->next->exists(a));
}

void node::remove(int a)
{
    if (this->data==a)
    {
        if (this->next==NULL)
            delete this;
        else
        {
            node* l=this->next;
            this->next=l->next;
            this->data=l->data;
            l->next=NULL;
            delete l;
        }
    }
    else
    {
        this->next->remove(a);
    }
}

list::list()
{
    this->root=new node();
}

list::~list()
{
    this->root->del();
    this->root=0;
}

void list::insert(int a)
{
    this->root->insert(a);
}

void list::print(){
   this->root->print();
}

bool list::exists(int a){
     return this->root->exists(a);
}

void list::remove(int a){
     this->root->remove(a);
}

int main()
{
    Container* c = new list();

    for(int i = 1; i < 30; i++)
        c->insert(i*i);

    cout << "Container after creation:" << endl;
    c->print();

    if(c->exists(25))
        cout << "Search for value 25: found" << endl;

    if(!c->exists(111))
        cout << "Search for value 111: not found" << endl;

    c->remove(25);
    c->remove(225);
    cout << "Container after deletion of the element:" << endl;
    c->print();

    delete c;
    return 0;
}

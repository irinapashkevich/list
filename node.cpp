#include <iostream>
#include "node.h"

using namespace std;

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

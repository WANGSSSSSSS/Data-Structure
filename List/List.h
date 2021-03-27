//
// Created by wang_shuai on 2021/3/27.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <vector>
#include <iostream>

using namespace std;

template<typename Data>
struct Listnode
{
    Data data;
    Listnode<Data>* next{NULL};
    Listnode(Data data)
    {
        this->data = data;
    }
};

template<typename Data>
class BasicList
{
private:
    Listnode<Data> *head;
public:
    virtual bool insert(int pos,Data data);
    virtual bool del(Data data);
    virtual bool del(int pos);
    virtual bool reserve_del(int i);
    bool create(vector<Data> vec);
    bool find(Data data);

    ostream& operator<<(ostream& os);
    friend ostream;
};


#endif //LIST_LIST_H

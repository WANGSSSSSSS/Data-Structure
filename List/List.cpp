//
// Created by wang_shuai on 2021/3/27.
//

#include "List.h"

template<typename Data>
bool BasicList<Data>::find(Data data)
{
    if(head != NULL)
    {
        Listnode<Data>* ptr = head;
        while(ptr != NULL)
        {
            if(ptr->data == data)
            {
                return true;
            }
            ptr = ptr->next;
        }
    }
    return false;
}

template<typename Data> bool BasicList<Data>::create(vector<Data> vec)
{
    if(vec.size() == 0)return true;

    Listnode<Data> *head = new Listnode<Data>(vec[0]);
    Listnode<Data> *node = head;
    for(int i=1; i<vec.size(); i++)
    {
           Listnode<Data> *_node = new Listnode<Data>(vec[i]);
           _node->next = NULL;
           node->next = _node;
           node = node->next;
    }
    return true;
}

template<typename Data> bool BasicList<Data>::insert(int pos, Data data)
{
    Listnode<Data> *ptr = head;

    if(pos == 0)
    {

        auto *node = new Listnode<Data>(data);
        node->next = head;
        head = node;
        return true;
    }

    while(--pos)
    {
        if(ptr == NULL)
        {
            return false;
        }
        ptr = ptr->next;
    }

    auto *node = new Listnode<Data>(data);
    node->next = ptr->next;
    ptr->next = node;

    return true;
}

template<typename Data> bool BasicList<Data>::del(int pos)
{
    if(pos == 0)
    {    if(head == NULL)return false;
        auto *node = head;
        head = head->next;
        delete node;
        return true;
    }

    auto *ptr = head;
    while(--pos)
    {
        if(ptr == NULL)
        {
            return false;
        }
        ptr = ptr->next;
    }
    auto *node = ptr->next;
    ptr->next = ptr->next->next;
    delete node;

    return true;
}
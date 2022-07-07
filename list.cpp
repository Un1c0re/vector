#include "list.h"

#include <iostream>


Item::Item() {
    prev = nullptr;
    next = nullptr;
    owner = nullptr;
}


Item::~Item() {
    if (owner) owner->RemoveItem(this);
}


List::List() {
    head = nullptr;
    tail = nullptr;
}


List::~List() {
    Clear();
}


void List::Add(Item* item) {
    if (!item)
        return;

    item->owner = this;

    if (!head) {
        item->prev = nullptr;
        item->next = nullptr;

        head = item;
        tail = item;
    }
    else {
        tail->next = item;

        item->prev = tail;
        item->next = nullptr;

        tail = item;
    }
}


Item* List::GetItem(int index) {
    Item* p;
    int i = 0;

    for (p = head; p; p = p->next, i++)
        if (i == index)
            return p;

    return nullptr;
}


int List::GetIndex(Item* item) {
    if (!item || item->owner != this)
        return -1;

    Item* p;
    int i = 0;
    for (p = head; p; p = p->next, i++) {
        if (p == item)
            return i;
    }
    return -1;

}


Item* List::Remove(int index) {
    Item* p = GetItem(index);
    if (!p)
        return nullptr;

    p->owner = nullptr;

    if (p->prev != nullptr)
        p->prev->next = p->next;
    else
        head = p->next;

    if (p->next != nullptr)
        p->next->prev = p->prev;
    else
        tail = p->prev;
    return p;
}


Item* List::RemoveItem(Item* item) {
    if (item->owner == this)
        return Remove(GetIndex(item));
    return nullptr;
}


void List::Delete(int index) {
    delete RemoveItem(GetItem(index));
}


int List::Count() {

    int count = 0;
    Item* p;
    for (p = head; p; p = p->next)
        count++;

    return count;
}


void List::Clear() {
    Item* next, * p;
    for (p = head; p; p = next) {
        next = p->next;
        delete p;
    }
    head = nullptr;
    tail = nullptr;
}
#pragma once

class List;

class Item {
private:
    Item* prev;
    Item* next;
    List* owner;

public:
    Item();
    virtual ~Item();

    friend class List;
};


class List {
private:
    Item* head;
    Item* tail;

public:
    List();
    ~List();

    void Add(Item* item);
    Item* GetItem(int index);
    int GetIndex(Item* item);
    Item* Remove(int index);
    Item* RemoveItem(Item* item);
    void Delete(int index);
    int Count();
    void Clear();
};

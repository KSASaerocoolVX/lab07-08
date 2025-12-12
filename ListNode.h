#ifndef LISTNODE_H
#define LISTNODE_H
#include "PCB.h"
class ListNode {
public:
    PCB data;
    ListNode* next;


    ListNode(const PCB& newData) : data(newData), next(nullptr) {}


    ~ListNode() {}
};
#endif //LISTNODE_H

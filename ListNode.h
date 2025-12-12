#ifndef LISTNODE_H
#define LISTNODE_H
class ListNode {
public:
    PCB data;
    ListNode* next;


    ListNode(const PCB& newData) : data(newData), next(nullptr) {}


    ~ListNode() {}
};
#endif //LISTNODE_H

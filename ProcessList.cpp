#include <iostream>
#include "ProcessList.h"

using namespace std;
    
ProcessList::ProcessList() : head(nullptr) {}

ProcessList::~ProcessList() {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

bool ProcessList::insert(const PCB& newPCB) {
    ListNode* newNode = new ListNode(newPCB);

    if (head == nullptr || head->data.processID >= newPCB.processID) {

        if (head != nullptr && head->data.processID == newPCB.processID) {
            delete newNode;
            return false;
        }

        newNode->next = head;
        head = newNode;
        return true;
    }
    ListNode* current = head;
    
    while (current->next != nullptr && current->next->data.processID < newPCB.processID) {
        current = current->next;
    }

    if (current->next != nullptr && current->next->data.processID == newPCB.processID) {
        delete newNode;
        return false;
    }

    newNode->next = current->next;
    current->next = newNode;
    return true;
}

bool ProcessList::remove(int pid) {
    if (head == nullptr) return false;

    if (head->data.processID == pid) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    ListNode* current = head;
    while (current->next != nullptr && current->next->data.processID != pid) {
        current = current->next;
    }

    if (current->next != nullptr) {
        ListNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
        return true;
    }

    return false;
}

void ProcessList::printList() {
    if (head == nullptr) {
        cout << "Список процессов пуст." << endl;
        return;
    }

    cout << "=== Текущий список процессов ===" << endl;
    ListNode* current = head;
    while (current != nullptr) {
        cout << "ID: " << current->data.processID 
             << " | Name: " << current->data.processName 
             << " | Status: " << current->data.processStatus 
             << " | Cmd: " << current->data.commandCounter << endl;
        current = current->next;
    }
    cout << "================================" << endl;
}
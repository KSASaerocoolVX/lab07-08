#include <iostream>
#include <vector>
#include "ProcessList.h"
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    ProcessList scheduler;
    cout << "1. Инициализация списка выполнена.\n" << endl;

    PCB p1 = {105, "Browser", "Running", 1024, {0, 1, 0, 0}};
    PCB p2 = {101, "System", "Running", 0, {0, 0, 0, 0}};
    PCB p3 = {103, "Editor", "Waiting", 55, {10, 20, 30, 40}};
    PCB p4 = {102, "Player", "Ready", 120, {5, 5, 5, 5}};

    cout << "2. Добавление процессов (105, 101, 103, 102)..." << endl;
    scheduler.insert(p1);
    scheduler.insert(p2);
    scheduler.insert(p3);
    scheduler.insert(p4);

    cout << "3. Проверка сортировки после вставок:" << endl;
    scheduler.printList();

    cout << "4. Удаление процесса с ID 103 (Editor)..." << endl;
    if (scheduler.remove(103)) {
        cout << "-> Успешно удалено." << endl;
    }

    cout << "5. Список после удаления:" << endl;
    scheduler.printList();

    cout << "6. Тест ошибок:" << endl;

    cout << "-> Попытка добавить дубликат ID 101: ";
    if (!scheduler.insert(p2)) {
        cout << "Ошибка (как и ожидалось, ID занят)." << endl;
    } else {
        cout << "Успех (ошибка логики!)." << endl;
    }

    cout << "-> Попытка удалить несуществующий ID 999: ";
    if (!scheduler.remove(999)) {
        cout << "Ошибка (как и ожидалось, ID не найден)." << endl;
    } else {
        cout << "Успех (ошибка логики!)." << endl;
    }

    cout << "7. Финальное состояние списка:" << endl;
    scheduler.printList();

    return 0;
}
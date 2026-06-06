#include <iostream>
using namespace std;

// 1. بناء هيكل العقدة (Node Structure)
class Node {
public:
    int value;
    Node* next;
    Node* prev;
};

// 2. بناء فئة القائمة المتصلة المزدوجة وإدارة العمليات عليها
class DoublyLinkedList {
private:
    Node* head = nullptr;

public:
    // إدخال عنصر في البداية (Insert at Beginning)
    void InsertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = head;
        newNode->prev = nullptr;

        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    // أصعب عملية 1: الإدخال بعد عقدة معينة (Insert After)
    void InsertAfter(Node* current, int value) {
        if (current == nullptr) {
            cout << "The given previous node cannot be NULL\n";
            return;
        }

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    // أصعب عملية 2: حذف عقدة معينة والربط الصحيح (Delete Node)
    void DeleteNode(Node*& head_ref, Node* delNode) {
        if (head_ref == nullptr || delNode == nullptr) return;

        // إذا كانت العقدة المراد حذفها هي رأس القائمة
        if (head_ref == delNode) {
            head_ref = delNode->next;
        }

        // إذا لم تكن العقدة المراد حذفها هي الأخيرة
        if (delNode->next != nullptr) {
            delNode->next->prev = delNode->prev;
        }

        // إذا لم تكن العقدة المراد حذفها هي الأولى
        if (delNode->prev != nullptr) {
            delNode->prev->next = delNode->next;
        }

        delete delNode;
    }

    // أصعب عملية 3: عكس القائمة بالكامل (Reverse Linked List)
    void Reverse() {
        Node* temp = nullptr;
        Node* current = head;

        // تبديل المؤشرات next و prev لجميع العقد
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev; // الانتقال للعقدة التالية (التي أصبحت prev بعد التبديل)
        }

        // إعادة تعيين الرأس (Head) ليصبح عند آخر عقدة تم الوصول إليها
        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    // البحث عن عقدة (Find Node)
    Node* Find(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->value == value) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    // طباعة القائمة بالكامل
    void PrintList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " <--> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};


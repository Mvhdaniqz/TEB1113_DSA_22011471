#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name, Node* next_ptr = nullptr) {
        this->name = name;
        this->next_ptr = next_ptr;
    }
};

class linkedlist {
public:
    Node* head;
    Node* tail;

    linkedlist(Node* head) {
        this->head = head;
        this->tail = head;
    }

    void add_element(Node* node) {
        tail->next_ptr = node;
        tail = node;
    }

    void display_list() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next_ptr;
        }
        cout << "nullptr" << endl;
    }

    void delete_by_value(string val) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->name == val) {
                if (prev == nullptr) {
                    head = current->next_ptr;
                    delete current;
                } else {
                    prev->next_ptr = current->next_ptr;
                    if (current == tail) tail = prev;
                    delete current;
                }
                return;
            }
            prev = current;
            current = current->next_ptr;
        }
    }
};

int main() {
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Ahmed");
    Node* node3 = new Node("Alee");

    linkedlist linkedlst(node1);
    linkedlst.add_element(node2);
    linkedlst.add_element(node3);

    linkedlst.display_list();

    // Test delete
    linkedlst.delete_by_value("Ahmed");
    linkedlst.display_list();

    return 0;
}
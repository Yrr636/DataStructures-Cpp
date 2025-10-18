// CircularLinkedList.cpp
// Implementation of a Circular Linked List in C++ (no STL)
// Author: YourName
// Date: October 2025
// Description: Demonstrates insertion, deletion, and traversal in a circular linked list.

#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Circular Linked List class
class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Insert a new node at the end
    void insertNode(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // circular link
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    // Delete a node by value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node *current = head, *prev = nullptr;

        // Case 1: head node deletion
        if (head->data == value) {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }

            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }

            last->next = head->next;
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Case 2: other node deletion
        do {
            prev = current;
            current = current->next;
        } while (current != head && current->data != value);

        if (current == head) {
            cout << "Node not found!\n";
            return;
        }

        prev->next = current->next;
        delete current;
    }

    // Display all elements
    void display() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }

    // Destructor to clean memory
    ~CircularLinkedList() {
        if (!head) return;
        Node* current = head;
        Node* nextNode;

        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);

        head = nullptr;
    }
};

// Example usage
int main() {
    CircularLinkedList cll;

    cll.insertNode(10);
    cll.insertNode(20);
    cll.insertNode(30);
    cll.insertNode(40);

    cout << "Circular Linked List elements:\n";
    cll.display();

    cout << "\nDeleting 20...\n";
    cll.deleteNode(20);
    cll.display();

    cout << "\nDeleting 10 (head)...\n";
    cll.deleteNode(10);
    cll.display();

    return 0;
}

/*
===============================
💡 Time Complexities:
-------------------------------
Insert: O(n)
Delete: O(n)
Display: O(n)
Space: O(n)
===============================
*/

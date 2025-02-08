#include <iostream>
#include <string>
using namespace std;

// Data class to store a string and an integer
class MonopolyBoard {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;

    MonopolyBoard(string propertyName, string propertyColor, int value, int rent) {
        this->propertyName = propertyName;
        this->propertyColor = propertyColor;
        this->value = value;
        this->rent = rent;
    }

    bool isEqual(MonopolyBoard other) {
        return propertyName == other.propertyName;
    }

    void print() {
        cout << "Property: " << propertyName << ", Color: " << propertyColor 
             << ", Value: $" << value << ", Rent: $" << rent << endl;
    }
};

// Template Node class
template <typename T> class Node {
public:
    T data;
    Node* nextNode;

    Node(T value) : data(value), nextNode(nullptr) {}
};

// Template LinkedList class
template <typename T> class CircularLinkedList {
private:
    Node<T>* headNode;
public:
    CircularLinkedList() : headNode(nullptr) {}

    bool isListEmpty() {
        return headNode == nullptr;
    }

    void insertAtHead(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (isListEmpty()) {
            headNode = newNode;
            headNode->nextNode = headNode;
        } else {
            Node<T>* temp = headNode;
            while (temp->nextNode != headNode) {
                temp = temp->nextNode;
            }
            temp->nextNode = newNode;
            newNode->nextNode = headNode;
            headNode = newNode;
        }
    }

    void insertAtTail(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (isListEmpty()) {
            headNode = newNode;
            headNode->nextNode = headNode;
        } else {
            Node<T>* temp = headNode;
            while (temp->nextNode != headNode) {
                temp = temp->nextNode;
            }
            temp->nextNode = newNode;
            newNode->nextNode = headNode;
        }
    }

    void insertAtPosition(T value, int position) {
        if (position == 0) {
            insertAtHead(value);
            return;
        }

        Node<T>* newNode = new Node<T>(value);
        Node<T>* temp = headNode;
        int count = 1;

        while (count < position && temp->nextNode != headNode) {
            temp = temp->nextNode;
            count++;
        }

        if (temp->nextNode == headNode && count < position) {
            cout << "Position out of bounds, inserting at tail" << endl;
            insertAtTail(value);
        } else {
            newNode->nextNode = temp->nextNode;
            temp->nextNode = newNode;
        }
    }

    void deleteAtHead() {
        if (isListEmpty()) {
            cout << "List is empty, no deletion performed" << endl;
            return;
        }

        if (headNode->nextNode == headNode) {
            delete headNode;
            headNode = nullptr;
        } else {
            Node<T>* temp = headNode;
            while (temp->nextNode != headNode) {
                temp = temp->nextNode;
            }
            Node<T>* toDelete = headNode;
            temp->nextNode = headNode->nextNode;
            headNode = headNode->nextNode;
            delete toDelete;
        }
    }

    void deleteAtTail() {
        if (isListEmpty()) {
            cout << "List is empty, no deletion performed" << endl;
            return;
        }

        if (headNode->nextNode == headNode) {
            delete headNode;
            headNode = nullptr;
        } else {
            Node<T>* temp = headNode;
            while (temp->nextNode->nextNode != headNode) {
                temp = temp->nextNode;
            }
            delete temp->nextNode;
            temp->nextNode = headNode;
        }
    }

    void deleteAtPosition(int position) {
        if (isListEmpty()) {
            cout << "List is empty, no deletion performed" << endl;
            return;
        }

        if (position == 0) {
            deleteAtHead();
            return;
        }

        Node<T>* temp = headNode;
        int count = 1;

        while (count < position && temp->nextNode != headNode) {
            temp = temp->nextNode;
            count++;
        }

        if (temp->nextNode == headNode) {
            cout << "Position out of bounds, no deletion performed" << endl;
        } else {
            Node<T>* toDelete = temp->nextNode;
            temp->nextNode = toDelete->nextNode;
            delete toDelete;
        }
    }

    void search(string propertyName) {
        if (isListEmpty()) {
            cout << "List is empty" << endl;
            return;
        }

        Node<T>* temp = headNode;
        do {
            if (temp->data.propertyName == propertyName) {
                temp->data.print();
                return;
            }
            temp = temp->nextNode;
        } while (temp != headNode);

        cout << "Property not found" << endl;
    }

    void printList() {
        if (isListEmpty()) {
            cout << "List is empty" << endl;
            return;
        }

        Node<T>* temp = headNode;
        do {
            temp->data.print();
            temp = temp->nextNode;
        } while (temp != headNode);
    }

    int countNodes() {
        if (isListEmpty()) {
            return 0;
        }

        int count = 0;
        Node<T>* temp = headNode;
        do {
            count++;
            temp = temp->nextNode;
        } while (temp != headNode);

        return count;
    }

    void reverseCLList() {
        if (isListEmpty()) return;

        Node<T>* prev = nullptr;
        Node<T>* current = headNode;
        Node<T>* next = nullptr;
        Node<T>* last = headNode;

        do {
            next = current->nextNode;
            current->nextNode = prev;
            prev = current;
            current = next;
        } while (current != headNode);

        headNode->nextNode = prev;
        headNode = prev;
    }

    void sortCLList() {
        if (isListEmpty()) return;

        bool swapped;
        Node<T>* ptr1;
        Node<T>* lptr = nullptr;

        do {
            swapped = false;
            ptr1 = headNode;

            do {
                if (ptr1->nextNode != headNode && ptr1->data.propertyName > ptr1->nextNode->data.propertyName) {
                    swap(ptr1->data, ptr1->nextNode->data);
                    swapped = true;
                }
                ptr1 = ptr1->nextNode;
            } while (ptr1->nextNode != headNode);

            lptr = ptr1;
        } while (swapped);
    }
};

// Main function to demonstrate the LinkedList class
int main() {
    // Create a LinkedList of MonopolyBoard objects
    CircularLinkedList<MonopolyBoard> list;

    // Check if the list is empty at the beginning
    if (list.isListEmpty()) {
        cout << "The list is currently empty." << endl;
    } else {
        cout << "The list is not empty." << endl;
    }

    // Inserting elements
    list.insertAtHead(MonopolyBoard("Bellagio", "Blue", 500, 50));
    list.insertAtTail(MonopolyBoard("Caesars Palace", "Green", 400, 40));
    list.insertAtPosition(MonopolyBoard("MGM Grand", "Yellow", 300, 30), 1);
    list.insertAtTail(MonopolyBoard("The Venetian", "Purple", 450, 45));
    list.insertAtTail(MonopolyBoard("Luxor", "Black", 250, 25));

    // Display the list and check if it's empty
    cout << "Properties after insertion:" << endl;
    list.printList();

    if (list.isListEmpty()) {
        cout << "The list is empty." << endl;
    } else {
        cout << "The list is not empty." << endl;
    }

    // Searching for a property
    list.search("MGM Grand");

    // Counting nodes
    cout << "Total properties: " << list.countNodes() << endl;

    // Deleting elements
    list.deleteAtHead();
    list.deleteAtPosition(1);
    list.deleteAtTail();

    // Check if the list is empty after deletions
    if (list.isListEmpty()) {
        cout << "The list is empty after deletions." << endl;
    } else {
        cout << "The list is not empty after deletions." << endl;
    }

    // Reversing the list
    cout << "Reversing the list:" << endl;
    list.reverseCLList();
    list.printList();

    // Sorting the list
    cout << "Sorting the list:" << endl;
    list.sortCLList();
    list.printList();

    return 0;
}

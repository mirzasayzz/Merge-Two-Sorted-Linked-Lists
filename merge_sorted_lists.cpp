#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    
    // Constructor
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to insert a node at the end of linked list
void insertAtEnd(Node* &head, int val) {
    Node* newNode = new Node(val);
    
    // If list is empty
    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    // Traverse to the end of list
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    
    temp->next = newNode;
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "Empty list" << endl;
        return;
    }
    
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

// Function to merge two sorted linked lists
Node* mergeSortedLists(Node* list1, Node* list2) {
    // If either list is empty, return the other list
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;
    
    // Create a dummy node as the head of the result list
    Node* dummyNode = new Node(0);
    // Pointer to track the current position in the result list
    Node* current = dummyNode;
    
    // Traverse both lists
    while (list1 != nullptr && list2 != nullptr) {
        // Compare current nodes from both lists
        if (list1->data <= list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    
    // If one list is not fully traversed, append the remaining nodes
    if (list1 != nullptr) {
        current->next = list1;
    } else {
        current->next = list2;
    }
    
    // Return the merged list (excluding the dummy node)
    Node* mergedList = dummyNode->next;
    delete dummyNode;
    return mergedList;
}

// Function to free the memory allocated for linked list
void freeList(Node* &head) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node *list1 = nullptr, *list2 = nullptr;
    int n1, n2, val;
    
    cout << "=======================================" << endl;
    cout << "   MERGE TWO SORTED LINKED LISTS" << endl;
    cout << "=======================================" << endl;
    
    // Input for first list
    cout << "\nEnter number of elements for first list: ";
    cin >> n1;
    
    if (n1 > 0) {
        cout << "Enter " << n1 << " elements in sorted order: ";
        for (int i = 0; i < n1; i++) {
            cin >> val;
            insertAtEnd(list1, val);
        }
    }
    
    // Input for second list
    cout << "\nEnter number of elements for second list: ";
    cin >> n2;
    
    if (n2 > 0) {
        cout << "Enter " << n2 << " elements in sorted order: ";
        for (int i = 0; i < n2; i++) {
            cin >> val;
            insertAtEnd(list2, val);
        }
    }
    
    // Display both lists
    cout << "\nFirst Linked List: ";
    displayList(list1);
    
    cout << "Second Linked List: ";
    displayList(list2);
    
    // Merge the lists
    Node* mergedList = mergeSortedLists(list1, list2);
    
    // Display merged list
    cout << "\nMerged Linked List: ";
    displayList(mergedList);
    
    // Free memory
    freeList(mergedList);
    
    return 0;
} 
/*
    Implement a queue with the following operations:
     - Put - Insert an element at the end of the queue
     - Pop - Remove the element from the front of the queue and return its value
     - Peek - Ge the value of the element from the front of the queue

    @author Christian Gonzalez Leon
    @date March 13th, 2017
*/

#include <iostream>

using namespace std;

// This type is as simple as needed

class Queue
{
 private:
    struct Node {
        Node* prev = nullptr;
        Node* next = nullptr;
        int value;
    };
    Node* first = nullptr;
    Node* last = nullptr;
 public:
    void put(int value) 
    {
        Node* new_node = new Node;
        new_node->value = value;
        if (first == nullptr) { // Empty queue
            first = last = new_node;
        } else {
            new_node->prev = last;
            last->next = new_node;
            last = new_node;
        }
    }
    int pop()
    {
        if (first == nullptr) {
            throw runtime_error("Cannot pop from an empty queue"); 
        }
        Node* node_to_delete = first;
        if (first == last) {
            first = last = nullptr;
        } else {
            first->next->prev = nullptr;
            first = first->next;
        }
        int value = node_to_delete->value;
        delete node_to_delete;
        return value;
    }
    int peek()
    {
        if (first == nullptr) {
            throw runtime_error("Cannot peek from an empty queue"); 
        } 
        return first->value;
    }
};

int main() 
{
    Queue queue;
    // Read from standard input
    int command_count, command, value_to_put;;
    cin >> command_count;

    while (command_count-- > 0) {
        cin >> command;
        switch (command) {
            case 1:
                cin >> value_to_put;
                queue.put(value_to_put);
                break;
            case 2:
                queue.pop();
                break;
            case 3:
                cout << queue.peek() << endl;
                break;
        }
    }

    return 0;
}

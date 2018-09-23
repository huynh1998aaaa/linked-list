#include <iostream>
using namespace std;

template <class T>
class Node{
    public:
        int data;
        Node *next;

        Node(int node_data) 
        {
            this->data = node_data;
            this->next = NULL;
        }
};
#include <iostream>

// First implementation of a simple linkedlist 
// By lordofwizard offcourse... i know i am awesome

class Node{
    public:
    int data;
    Node * next;

    Node(int data){
        this->data = data;
    }
};

class LinkedList{
    Node * head;
    public: 
    LinkedList(){
        this->head = NULL;
    }

    void insert(int data){
        Node * new_node = new Node(data);
        new_node->next = this->head;
        this->head = new_node;
    }

    void print(){
        Node * current = this->head;
        while(current != NULL ){
            std::cout << current->data << "  ";
            current = current-> next;
        }
        std::cout<<std::endl;
    }
};

int main(){
    LinkedList l;
    l.insert(10);
    l.insert(15);
    l.insert(2);
    l.print();
    return 0;
}

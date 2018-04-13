#include <iostream>
using namespace std;

template<typename T>

class queue_t{
    
private:
    struct node_t{
        node_t* next;
        T value;
    };
    
    node_t* head;
    node_t* tail;
    
public:
    
    queue_t(){
        head=nullptr;
        tail=nullptr;
    }
    
    ~queue_t() {
        if (head == nullptr) {
            return;
        }
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        while (head) {
            pop();
        }
        
        head = nullptr;
        tail = nullptr;
        return;
    }
    
    void push(T new_value){
        if (head==nullptr) {
            head = new node_t;
            head->value = new_value;
            head->next = nullptr;
            tail = head;
            return;
        }
        tail->next = new node_t;
        tail->next->value = new_value;
        tail->next->next = nullptr;
        tail = tail->next;
        return;
    }
    
    T pop(){
        if (head == nullptr) {
            cout<<"Empty tree"<<endl;
        }
        T remove = head->value;
        node_t* new_head = head->next;
        if(tail == head) {
            tail = nullptr;
            new_head = nullptr;
        }
        delete head;
        head = new_head;
        return remove;
    }
    
    void show_queue(){
        for (node_t* n = head; n != nullptr; n = n->next) {
            cout<<n->value<<" ";
        }
        return;
    }
    
    queue_t( const queue_t & other) {
        head = nullptr;
        tail = nullptr;
        for (node_t* n = other.head; n != nullptr; n = n->next) {
            push(n->value);
        }
        
    }
};



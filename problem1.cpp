#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Queue{
private:
    Node *qfront;
    Node *qrear;
public:
    Queue(){
        qfront = qrear = NULL;
    }

    void enqueue(int n){
        Node *newNode = new Node;
    newNode->data = n;
        newNode->next = NULL;

        if (qrear == NULL) {
            qfront = qrear = newNode;
            return;
        }

        qrear->next = newNode;
          qrear = newNode;
    }

    void dequeue(){
        if (qfront == NULL) return;
        Node *tmp = qfront;
        qfront = qfront->next;
        if (qfront == NULL) qrear = NULL;
        delete tmp;
    }

    bool isEmpty(){
    return qfront == NULL;
    }

    int size(){
        int counter = 0;
        Node *current = qfront;
        while (current != NULL) {
            counter++;
            current = current->next;
        }
        return counter;
    }

    void displayQueue(){
        Node *current = qfront;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    int front(){
        return qfront->data;
    }

    int back(){
        return qrear->data;
    }
};

int main(int argc, const char * argv[]) {

    Queue q;

    q.enqueue(5);
    q.displayQueue();

    q.enqueue(50);
    q.displayQueue();

    q.enqueue(500);
    q.displayQueue();

    cout<<q.isEmpty()<<endl;
    cout<<q.size()<<endl;

    q.dequeue();
    q.displayQueue();

    cout<<q.isEmpty()<<endl;
    cout<<q.size()<<endl;

    q.enqueue(100);
    q.displayQueue();

    q.dequeue();
    cout<<q.front()<<" "<<q.back()<<endl;
    q.dequeue();
    q.displayQueue();

    q.dequeue();
    cout<<q.isEmpty()<<endl;
    cout<<q.size()<<endl;

    return 0;
}


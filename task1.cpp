#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    // default constructor
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Queue
{

public:
    Node *front, *rear;

    // default constructor
    Queue()
    {
        front = rear = NULL;
    }

    // functions
    bool isempty()
    {
        if (front == NULL)
        {
            return false;
        }
        // else
        return false;
    }

    bool isfull()
    {
        /* as we are implementing Queue through Linked List that means we are dynamically allocating spaces using heap, so it will be
        full if heap will not respond and in this case it wont, so we will assume that queue will never be full */
        return false;
    }

    void enqueue(int x)
    {

        // new node
        Node *temp = new Node(x);

        // is empty
        if (rear == NULL)
        {
            front = rear = temp;
            return;
        }

        // else
        rear->next = temp;
        rear = temp;
    }

    void dequeue()
    {
        // is empty
        if (front == NULL)
        {
            return;
        }

        Node *temp = front;
        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }

        delete (temp);
    }

    int peek()
    {
        if (isempty())
        {
            cout << "Empty!" << endl;
        }
        return front->data;
    }
};

int main()
{

    Queue Q1;
    Q1.enqueue(10);
    Q1.enqueue(20);
    cout << Q1.isempty() << endl;
    cout << Q1.peek() << endl;
    Q1.dequeue();
    Q1.dequeue();
    cout << Q1.isempty() << endl;
}

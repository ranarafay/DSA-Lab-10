#include <iostream>
using namespace std;

class Node
{
public:
	Node* next;
	string task_name;
	int time;

public:
	Node()
	{
		time = 0;
		task_name = "TEMP";
		next = NULL;
	}
	Node(int time, string task_name)
	{
		this->time = time;
		this->task_name = task_name;
		next = NULL;
	}
};

class Queue
{
public:
	Node* head = NULL;
	Node* tail = NULL;

public:
	bool isEmpty()
	{
		if (head == NULL)
		{
			return true;
		}
		else
			return false;
	}

	// Queue made using Linked List can't be full

	void Enqueue(string task_name, int time)
	{
		Node* nnode = new Node(time,task_name);
		if (isEmpty())
		{
			head = nnode;
			tail = nnode;
		}
		else
		{
			tail->next = nnode;
			nnode->next = NULL;
			tail = nnode;
		}
	}

	void Dequeue()
	{
		Node* nnode;
		if (head == NULL && tail == NULL)
		{
			cout << "Queue Empty" << endl;
		}
		else
		{
			nnode = head;
			head= head->next;
			nnode->next = NULL;
			delete nnode;
		}
	}

	int peek()
	{
		return head->time;
	}

	void Display()
	{
		Node* temp = head;
		while (temp!= NULL)
		{
			cout << temp->task_name << endl;
			cout << temp->time << ":00 Seconds" << endl;
			cout << endl;
			temp = temp->next;
		}
	}
};

void Robin(Queue q, int quantum)
{
	//cout << q.head->task_name << endl;

	while (!q.isEmpty())
	{
		if (quantum >= q.head->time )
		{
			cout << q.head->task_name << "  Execution Time: " << q.head->time << ":00 Seconds" << endl;
			cout << "Remaining Execution Time: 0:00 Sec" << endl;
			cout << "Status: Completed " << endl;
			cout << endl;
			q.Dequeue();
		}
		else
		{
			cout << q.head->task_name << "  Execution Time: " << q.head->time << ":00 Seconds" << endl;
			cout << "Remaining Execution Time: " << q.head->time - quantum << ":00 Seconds" << endl;
			cout << "Status: Not Completed Pushed Down the Queue " << endl;
			cout << endl;

			string temp = q.head->task_name;
			int t = q.head->time - quantum;
			q.Dequeue();
			q.Enqueue(temp, t);
		}
	}
}
int main()
{
	Queue q1;
	q1.Enqueue("Task 1", 10);
	q1.Enqueue("Task 2", 30);
	q1.Enqueue("Task 3", 30);
	q1.Enqueue("Task 4", 40);
	q1.Enqueue("Task 5", 50);


	int Quantum = 20;
	Robin(q1, 20);
	//q1.Display();
}

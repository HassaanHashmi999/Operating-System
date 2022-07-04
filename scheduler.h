#pragma once
#include<iostream>
#include<string>
#include"processes.h"
using namespace std;
struct Data {
	processes info;
	Data* next;	
    Data(processes dat)
    {
        info=dat;
        next=NULL;
    }		
};

class Run_Q {


	Data* front;//begining of the list
	Data* rear;//ending 
	
public:

	Run_Q()
	{
		front = NULL;//declare null when an object is declared to prevent from garbage value
		rear = NULL;
		
	}
	void enqueue(processes data)
	{
		Data* newnode;//new node 
		newnode = new Data(data);//dynamically declared
		

		if (rear==NULL) //check so the head can be intialized
		{
			front= rear = newnode;
			
		}
		else
		{
			rear->next = newnode;//movement to next node so tail can be declared
			rear = newnode;
		}
		
	}

	void dequeue() {
		
		if (front==NULL)
			{
                cout << "The queue is empty.\n";
                return ;
            }
		else
		{
			Data* temp=front;
            front=front->next;

            if(front==NULL)
            rear=NULL;
            delete(temp);
		}
		

	}
	void print()//it was declared only to check the input given
	{
		Data* tmp;
		tmp = front;
		while (tmp != NULL)//until reahces rear's next (null)
		{
			cout << tmp->info.Arrival_Time << endl;
			tmp = tmp->next;
		}
	}

	~Run_Q() {
		while (front==NULL) {
			Data* n = front;
			front = front->next;
			delete n;
		}
	}
}obj;


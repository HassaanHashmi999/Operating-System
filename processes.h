#pragma once
#include<string>
#include <stack>
using namespace std;


class processes
{
public:
    string PROCNAME;
    int PRIORITY;
    float Arrival_Time;
    char state[1];
    float Cpu_time;
    float I_Otime;
    int processid;
    string pstate;
    

}proc[8];


class PCB
{

processes* Pcb_;

PCB()
{
    for(int i=0;i<8;i++)
    {
        stack<int> stack;
    stack.push(proc[i].PRIORITY);
    stack.push(proc[i].Cpu_time);
   
    }

}
};
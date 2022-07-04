#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>
#include<iostream>
#include"processes.h"
#include"scheduler.h"
#include<fstream>
#include<sstream>
using namespace std;
int t_RT;
pthread_mutex_t mutex1;
char* S_type;
pthread_t controller;
pthread_t *CPU_T;
 float deer[8];
void FCFS()
{	
	int n=8;
	 int i, j;
    for (i = 0; i < n - 1; i++)
 {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++){
            if (proc[j].Arrival_Time > proc[j + 1].Arrival_Time){
                swap(proc[j], proc[j+1]);
                }
                	}
                }
				for(int k=0;k<8;k++)
				{
					for(int l=0;l<proc[k].Cpu_time;l++)
					{
						++t_RT;
					}
				}

				
}

void scheduler()
{
	if(strcmp(S_type, "f") == 0)
	FCFS();
	else if(strcmp(S_type, "r") == 0)
	;//RR();
	else if(strcmp(S_type, "p") == 0)
	;//PR();

}
void idle();
void yeild();
void wakeup()
{
	static int z=1;
	cout<<"THE PROCESSES ARE CREATED AND ARE IN READY QUEUE     core:"<<z<<endl;
	++z;
	scheduler();
}
void terminate();
void preempt()
{
	
}

void *simulate(void *arg){
	pthread_mutex_lock ( &mutex1 );
	wakeup();
	sleep(1);
	pthread_mutex_unlock ( &mutex1 ) ;
pthread_exit(0);
}


void start(char* file,int cc)
{
	CPU_T= new pthread_t(cc);
	
    float found;
    ifstream in;
   // cout<<file<<"SS"<<endl;
	in.open(file);
    int ichk = 0;
	string st;
		
        for(int i=0;i<8;i++){
		while (getline(in, st))//get line as string
		{

			stringstream ss(st);
			string word;//string
			while (ss >> word)
            {//taking a word in from stringstream one by one
			cout<<word<<endl;
            }  
	
        }
		}

	for(int i=0;i<cc;i++){
		pthread_create(&CPU_T[i], NULL, simulate, (void*)file);
		pthread_join(CPU_T[i], NULL);
	}
}
	



//The scheduler than decides what process/thread to run next. This process is executed as a
//return from its terminate()call.
int main(int argc,char* argv[])
{
    char* inputfile=argv[1];
    int No_CPU=atoi(argv[2]);
    S_type=argv[3];
    int timeslice=atoi(argv[4]);
    char* outputfile=argv[5];
    if(No_CPU==3 || No_CPU>4 || No_CPU<0)
    return 1;
    
    start(inputfile,No_CPU);
	sleep(3);
	
	cout<<"THE TOTAL RUNTIME IS::"<<t_RT<<endl;
}
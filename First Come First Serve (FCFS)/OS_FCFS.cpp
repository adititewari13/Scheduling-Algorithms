#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
int warning=1,max_arrival=-1,min_arrival=INT_MAX;
float avg_tat=0.0 ,avg_wt=0.0;
struct Processes
   {
      int pid=0;                                                                        
      int arr_time=0;                              
	    int burst_time=0;   
      int start_time=0;       
      int comp_time=0;                                                 
      int ta_time=0;                           
	    int waiting_time=0;   
      int response_time=0;                                           
   };

bool comparison_ArrivalTime(Processes a,Processes b)
{
    return (a.arr_time < b.arr_time);
}
bool comparison_PID(Processes a,Processes b)
{
    return (a.pid < b.pid);
}

int Show_Process(Processes p[],int n,bool b=false)
{
    if(b==false)
    {
        cout<<"\nPID || Arrival Time || Burst Time\n";
        for(long i=0;i<n;i++)
         {
            cout<<p[i].pid<<"\t"<<p[i].arr_time<<"\t\t"<<p[i].burst_time<<"\n";
         }
        cout<<endl<<endl;
    }
    if(b==true)
    {
        cout<<"\nPID || Arrival Time || Burst Time || Completion Time || Turn-Around time || Waiting Time || Response Time\n";
        for(long i=0;i<n;i++)
        {
            cout<<" "<<p[i].pid<<"\t"<<p[i].arr_time<<"\t\t"<<p[i].burst_time<<"\t\t"<<p[i].comp_time<<"\t\t\t"<<p[i].ta_time<<"\t\t"<<p[i].waiting_time<<"\t\t"<<p[i].response_time<<"\n";
        }
        cout<<endl;
        cout<<"Average Turn-Around Time= "<<fixed<<setprecision(3)<<avg_tat<<endl;
        cout<<"Average Waiting Time= "<<fixed<<setprecision(3)<<avg_wt<<endl<<endl;
    }
    return 0; 
}

int Enter_processes(Processes p[],int n)
{
    cout<<"************************************************************************************************\n";
    int pid=1;
    for(int i=0;i<n;i++)
      {
        cout<<"\tFOR PROCESS:"<<i+1<<endl;
        p[i].pid=pid;
        cout<<"\tEnter Arrival Time:";
        cin>>p[i].arr_time;
        while(p[i].arr_time<0)
	      {
		    cout<<"\t\t\t\tWarning "<<warning<<": A Process Cannot Have Arrival Time In Negative.\n";
		    cout<<"\tPlease Enter Arrival Time Again:";
		    cin>>p[i].arr_time;
		    warning++;
	      }
        if(p[i].arr_time<min_arrival)
          {
            min_arrival=p[i].arr_time;
          }
        if(p[i].arr_time>max_arrival)
          {
            max_arrival=p[i].arr_time;          
          }
        cout<<"\tEnter Burst Time:";
        cin>>p[i].burst_time;
        
        while(p[i].burst_time<=0)
	       {
            /*Program Will throw Error If Burst Time is Zero.*/
		    cout<<"\t\t\t\tWarning "<<warning<<": A Process Cannot Have Burst Time Smaller than 1\n";
		    cout<<"Please Enter Burst Time Again:";
		    cin>>p[i].burst_time;
		    warning++;
	       }
        cout<<endl;
        pid++;
    }
    return 0;
}

int calculate(Processes p[], int n)
  {
      for(int i=0;i<n;i++)
       {
         p[i].start_time=(i==0)?p[i].arr_time:max(p[i-1].comp_time,p[i].arr_time);
         p[i].comp_time=p[i].start_time + p[i].burst_time;
         p[i].ta_time=p[i].comp_time - p[i].arr_time;
         p[i].waiting_time=p[i].ta_time - p[i].burst_time;
         p[i].response_time=p[i].start_time-p[i].arr_time;
       }
      
      for(int i=0; i<n; i++)
       {
          avg_tat= avg_tat + p[i].ta_time;
          avg_wt= avg_wt + p[i].waiting_time;
       }
       
      avg_tat= avg_tat/n;
      avg_wt= avg_wt/n;
      
      return 0;
  }

int main()
 {
    int n,time=0;
    cout<<"Enter No Of Processes:";
    cin>>n;
    while(n==0)
	   {
		   cout<<"\t\t\t\tWarning "<<warning<<": There Cannot Be Zero Processes.\n";
		   cout<<"Please Enter the No. of Processes Again:";
		   cin>>n;
		   warning++;
	   }
    Processes p[n];
    Enter_processes(p,n);
    sort(p,p+n,comparison_PID);
    sort(p,p+n,comparison_ArrivalTime);
    Show_Process(p,n);
    calculate(p,n);
    Show_Process(p,n,true);
    system("pause");
    return 0;
 }
    

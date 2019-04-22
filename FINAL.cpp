#include<stdio.h>
#include<iostream>
#include<unistd.h>
using namespace std;

struct process
{
	int p_id;
	int prio;
	int t_burst;
	int t_arrival;
	int t_wait;
};
struct line{
    int prio_st;
    int prio_end;
    int len = 0;
    process *p;
};
void calculate();
int n;
struct process o[100],o1[100],o2[100],o3[100];
int p[100],b[100],a[100],o1save[100],o2save[100],o3save[100];
int j,k[3],g=0;
float avg_wait=0,avg_turn=0;


int main()
{   
	line q[3];
    q[0].prio_st = 1;
    q[0].prio_end = 3;
    q[1].prio_st = 4;
    q[1].prio_end = 6;
    q[2].prio_st = 7;
    q[2].prio_end = 9;
	
	cout<<"\t\t MULTILEVEL QUEUE SCHEDULING\n";
	cout<<"For FCFS enter priority between 1 and 3\n";
	cout<<"For Priority Sheduling enter priority between 4 and 6\n";
	cout<<"For Round Robin Algorithm enter priority between 7 and 10\n";
	
	cout<<"\n NUMBER OF PROCESS TO BE ENTERED :";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cout<<"\nP["<<(i+1)<<"] :Enter Priority of process :";
		cin>>p[i];
		int x=p[i];
		o[i].p_id=p[i];
		cout<<"Enter Burst Time and Arrival Time :";
		cin>>b[i]>>a[i];
		for(int j=0;j<3;j++){
        if(q[j].prio_st<=x &&x<=q[j].prio_end){
            q[j].len++;
        }
        
    }
    		
	}
	//o=p;

	for(int i =0;i<3;i++){
        int len = q[i].len;
        q[i].p = new process[len];
    }
	int aa=0;
    int bb=0;
    int cc=0;

    for(int i =0;i<3;i++){    //i=0
        for(int j=0;j<n;j++){
            if((q[i].prio_st<=o[j].p_id) && (o[j].p_id<=q[i].prio_end)){
                if(i==0){
                    q[i].p[aa++] = o[j];

                    }
                else if(i==1){
                    q[i].p[bb++] = o[j];
                    }
                else{
                    q[i].p[cc++] = o[j];
                    }
            }
        }
    }

    aa--;bb--;cc--;
    for(int i=0;i<3;i++){
        cout<<"Queue "<<i+1<<" : \t";
        for(int j=0;j<q[i].len;j++){
            cout<<q[i].p[j].p_id<<"->";
        }
        cout<<"NULL\n";
    }

	
	for(int y=0;y<n;y++)
	{
		if(a[y]==0)
		    g++;
	}
	
	k[1]=0;k[2]=0;k[3]=0;
	for(int i=0;i<n;i++)
	{
		 if(p[i]<=q[0].prio_end&&p[i]>=q[0].prio_st)
		      { 
			  o1[k[1]].p_id=i+1;
		      o1[k[1]].prio=p[i];
		      o1[k[1]].t_burst=b[i];
		      o1save[k[1]]=o1[k[1]].t_burst;
		      o1[k[1]].t_arrival=a[i];
			  k[1]++;
			  }
		 else if(p[i]>=q[1].prio_st &&p[i]<=q[1].prio_end ) 
		      {
			  o2[k[2]].p_id=i+1; 
		      o2[k[2]].prio=p[i];
		      o2[k[2]].t_burst=b[i];
		      o2save[k[2]]=o2[k[2]].t_burst;
		      o2[k[2]].t_arrival=a[i];
		      k[2]++;
			  }
		 else if(p[i]>=q[2].prio_st&&p[i]<=q[2].prio_end ) 
		      {
			  o3[k[3]].p_id=i+1; 
		      o3[k[3]].prio=p[i];
		      o3[k[3]].t_burst=b[i];
		      o2save[k[2]]=o2[k[2]].t_burst;
		      o3[k[3]].t_arrival=a[i];
		      k[3]++;
			  }     
	}
	cout<<"\n \t Lowest prio range Queue ("<<k[1]<<" Process) \t (FCFS)\n";
	if(k[1]==0)
		cout<<"No process In present queue\n\n";
	else
	{
		cout<<"\n PID          \t: ";
	    for(int j=0;j<k[1];j++)
		{
		 	cout<<o1[j].p_id<<"\t";
		}
		cout<<"\n prio     \t:";
		for(int j=0;j<k[1];j++)
		{
		 	cout<<o1[j].prio<<"\t";
		}
		cout<<"\n Arrival Time \t:";
		for(int j=0;j<k[1];j++)
		{
		 	cout<<o1[j].t_arrival<<"\t";
		}
		cout<<"\n Burst Time   \t:";
		for(int j=0;j<k[1];j++)
		{
		 	cout<<o1[j].t_burst<<"\t";
		}
    }
	cout<<"\nQ2---Middle prio range Queue ("<<k[2]<<" process)\t(prio Sheduling)\n";
	if(k[2]==0)
	    cout<<"No process In present queue\n\n";
	else
	{
	    cout<<"\n PID          \t: ";
	    for(int j=0;j<k[2];j++)
		{
		 	cout<<o2[j].p_id<<"\t";
		}
		cout<<"\n prio     \t:";
		for(int j=0;j<k[2];j++)
		{
		 	cout<<o2[j].prio<<"\t";
		}
		cout<<"\n Arrival Time \t:";
		for(int j=0;j<k[2];j++)
		{
		 	cout<<o2[j].t_arrival<<"\t";
		}
		cout<<"\n Burst Time   \t:";
		for(int j=0;j<k[2];j++)
		{
		 	cout<<o2[j].t_burst<<"\t";
		}
	} 
	cout<<"\nQ3---Highest prio range Queue  ("<<k[3]<<" process) (Round Robin scheduling)\n";
	if(k[3]==0)
		cout<<"No process In present queue"<<endl<<endl;
    else
    {
		cout<<"\n PID          \t: ";
	    for(int j=0;j<k[3];j++)
		{
		 	cout<<o3[j].p_id<<"\t";
		}
		cout<<"\n prio     \t:";
		for(int j=0;j<k[3];j++)
		{
		 	cout<<o3[j].prio<<"\t";
		}
		cout<<"\n Arrival Time \t:";
		for(int j=0;j<k[3];j++)
		{
		 	cout<<o3[j].t_arrival<<"\t";
		}
		cout<<"\n Burst Time   \t:";
		for(int j=0;j<k[3];j++)
		{
		 	cout<<o3[j].t_burst<<"\t";
		}	
	}  
	{
	
	int o=0;
	int m,t=0,imp=0,Queuecount=0,Qsize=0,flag[k[1]],flag1[k[2]],flag2[k[3]],sig=0,sig1=0,sig2=0;
	int Q[3];
	 for(int m=0;m<3;m++)
    {  
	    Q[m]=1;
    }
    for(int m=0;m<k[1];m++)
    {  
	    flag[m]=1;
	    o1[j].t_wait=0;
    }
    for(int m=0;m<k[2];m++)
    {  
	    flag1[m]=1;
    }
    for(int m=0;m<k[3];m++)
    {  
	    flag2[m]=1;
    }
    struct process x;  //sorting Q2 according to the prio 
		    	for(int u=0;u<k[2];u++)
		    	{
		    		for(int r=u;r<k[2];r++)
		    		{
		    		if(o2[u].prio<o2[r].prio)
		    		{
		    			x=o2[u];
		    			o2[u]=o2[r];
		    			o2[r]=x;
		    		}
				  }
				}
    struct process y;  //sorting Q1 according to the t_arrival time
	for(int u=0;u<k[1];u++)
	{
		for(int r=u;r<k[1];r++)
		{
		    if(o1[u].t_arrival>o1[r].t_arrival)
		    {
		    	y=o1[u];
		    	o1[u]=o1[r];
		    	o1[r]=y;
		    }
		}
	}
	struct process z; //sorting Q2 according to the Arrival time
		    	for(int u=0;u<k[3];u++)
		    	{
		    		        for(int r=u;r<k[3];r++)
		    		        {
		    		          if(o3[u].t_arrival>o3[r].t_arrival)
		    		           {
		    		            	z=o3[u];
		    		            	o3[u]=o3[r];
		    		            	o3[r]=z;
		    		         }
				             }
				}		
	cout<<"----------------------------------------------------------------------------";				
	cout<<"\nSCHEDULING OF PROCESS \n";
	int p=0,p1=0,p2=0;
	while(t<=90)
	{	
    if(Q[imp]==0)
	{
		for(int m=0;m<3;m++)
	    {
	        if(Q[m]==0)
		    {
		   	    Queuecount++;
		    }
	    }
        	if(Queuecount==3)
	        { 
	            break;
	            break;
	        }  
	        }
  else{
	switch(imp)
	{
		case 0:
		    {
		    	//Lowest prio range Queue
		    	int count=0;	
        	    int e=t+10;
        	    if(k[1]==0){
        	    	Q[0]=0;
        	    	break;
			    }
        	  else{
           	  while(t<=e)
	          {		
	              if(flag[p]==0)
				  {
		          for(int m=0;m<k[1];m++)
	              {
	        	         if(flag[m]==0)
		                 {
		   	                    count++;
		                 }
	              }
        	      if(count==k[1])
	              { 
	                     Q[0]=0; 
	                     break;
	              }  
	              }
	              else
	              {	
	                   o1[p].t_wait+=(t-o1[p].t_wait);
	                   if(o1[p].t_arrival>t)
					   {
					   	   sig++;
						} 
	                   else if(o1[p].t_arrival<=t)
	                   {	
             		   int remtime=o1[p].t_burst;
             		   if((t+remtime)>e && remtime>0)
             		   {
             		   	  int h=t+remtime;
					      remtime=h-e;
						  o1[p].t_burst=remtime;		   
             		   	  cout<<"\t IN QUEUE Q1\n\t p"<<o1[p].p_id<<" TAKES TIME FROM "<<t<<"---"<<e<<" sec\n";
             		   	  t=e;
             		   	  break;
						}
             		    else if(remtime<=10)
					    {
					     cout<<"\t IN QUEUE Q1\n\t p"<<o1[p].p_id<<" TAKES TIME FROM "<<t<<"---"<<(t+remtime)<<" sec\n";
					     flag[p]=0;
					     t+=remtime;
					     o1[p].t_burst=0;
					   }
					   else if(remtime>10)
					   {
					   	  cout<<"\t IN QUEUE Q1\n\t p"<<o1[p].p_id<<" TAKES TIME FROM "<<t<<"---"<<(t+10)<<" sec\n";
					   	  t=t+10;
					      o1[p].t_burst-=10;
					   }   
             		  }
             		  if(sig==k[1])
             		  { break;
					   }
             		    sleep(1);
    					p++;
    					p=p%k[1];}
    					
				}
		     }
		    }   
		    break;	
	    case 1:
		    {
		    	//Middle prio range Queue
		    	int count=0;
		    	 int e=t+10;
        	  if(k[2]==0){
        	  	Q[1]=0;
			  }
        	  else{
           	  while(t<=e)
	          {		
	              if(flag1[p1]==0)
				  {
		          for(int m=0;m<k[2];m++)
	              {
	        	         if(flag1[m]==0)
		                 {
		   	                    count++;
		                 }
	              }
        	      if(count==k[2])
	              { 
	                     Q[1]=0; 
	                     break;
	              }  
	              }
	              else
	              {	
	                  o2[p1].t_wait+=(t-o2[p1].t_wait);
	                  if(o2[p1].t_arrival>t)
					   {
					   	   sig1++;
						} 
	                  else if(o2[p1].t_arrival<=t)
	                   {
	                  int QTime=10;
             		   int remtime=o2[p1].t_burst;
             		   if(t+remtime>e && remtime>0)
             		   {
             		   	  int h=t+remtime;
					      remtime=h-e;
						  o2[p1].t_burst=remtime;		   
             		   	  cout<<"\t IN QUEUE Q2\n\t p"<<o2[p1].p_id<<" TAKES TIME FROM "<<t<<"---"<<e<<" sec\n";
             		   	  t=e;
             		   	  break;
             		   	
						}
             		   
					   else if(remtime<=10)
					   {
					     cout<<"\t IN QUEUE Q2\n\t p"<<o2[p1].p_id<<" TAKES TIME FROM "<<t<<"---"<<(t+remtime)<<" sec\n";
					     flag1[p1]=0;
					     t+=remtime;
					     o2[p1].t_burst=0;
					   }
					   else if(remtime>10)
					   {
					      cout<<"\t IN QUEUE Q2\n\t p"<<o2[p1].p_id<<" TAKES TIME FROM "<<t<<"---"<<(t+10)<<" sec\n";
					      o2[p1].t_burst-=10;
					      t=t+10;
					   }    	    
	              
	              }}
	              if(sig1==k[2])
             		  { break;
					   }
	                sleep(1);
    					p1++;
    					p1=p1%k[2];
    		        	}	
			         }  
			        
		        }
		        break;
		case 2:
			{
				//Highest prio range Queue
			  int count=0;	
         	  int e=t+10;
        	  if(k[3]==0){
        	  	Q[2]=0;
			  }
        	  else{
           	  while(t<=e)
	          {		
	              if(flag2[p2]==0)
				  {
		          for(int m=0;m<k[3];m++)
	              {
	        	         if(flag2[m]==0)
		                 {
		   	                    count++;
		                 }
	              }
        	      if(count==k[3])
	              { 
	                     Q[2]=0;
	                     break;
	               }  
	              }
	              else
	              {	
	                  o3[p2].t_wait+=(t-o3[p2].t_wait);
	                  if(o3[p2].t_arrival>t)
					   {
					   	   sig2++;
						} 
	                    if(o3[p2].t_arrival<=t)
	                   { 
             			int time_quantum=4;
	            		int remtime=o3[p2].t_burst;   
	            		if((t+remtime)>e && remtime>0 && remtime<=4)
	          			{  
	                 		int h=t+remtime;
	                 		remtime=h-e; 
	                 		o3[p2].t_burst=remtime;
	                 		cout<<"\t IN QUEUE Q3\n\t p"<<o3[p2].p_id<<" TAKES TIME FROM "<<t<<"---"<<e<<" sec\n";
	                 		t=e;
	                  		break;
	           			}    
	           			else if(remtime<=time_quantum)
	            		{   
							
	                 		cout<<"\t IN QUEUE Q3\n\t p"<<o3[p2].p_id<<" TAKES TIME FROM "<<t<<"---"<<(t+remtime)<<" sec\n";
	                    	t+=remtime;
	                    	o3[p2].t_burst=0;
		                	flag2[p2]=0;
	            		}
	                    else
	  					{	 
	  					     cout<<"\t IN QUEUE Q3\n\t p"<<o3[p2].p_id<<" TAKES TIME FROM "<<t<<"---"<<(t+time_quantum)<<" sec\n";
	     					 o3[p2].t_burst-=time_quantum;
	     					 t+=time_quantum;
       					}
                        }}
                        if(sig2==k[3])
             		   { break;
					   }
                        sleep(1);
    					p2++;
    					p2=p2%k[3];
    					break;
    			}
			} 
			}
			
            
		
		}
    }    
imp++;
imp=imp%3;
}
calculate();
}
}

void calculate()
{
	
cout<<"----------------------------------------------------------------------------";
cout<<"\n CALCILATION FOR AVERAGE WAITING TIME AND TURNAROUND TIME:\n";
cout<<"----------------------------------------------------------------------------";
for(int j=0;j<k[1];j++)
{   
    cout<<"\n\nIn Queue Q1: P"<<o1[j].p_id<<"\n";
    if(j!=0){
		cout<<"Waiting Time\t "<<"Turnaround time\t"<<"\n";
		cout<<(o1[j].t_wait-o1[j-1].t_arrival-o1[j].t_arrival)<<"sec"<<"\t\t\t"<<((o1[j].t_wait-o1[j-1].t_arrival-o1[j].t_arrival)+o1save[j])<<" sec\n";
		avg_turn+=((o1[j].t_wait-o1[j-1].t_arrival-o1[j].t_arrival)+o1save[j]);
		avg_wait+=(o1[j].t_wait-o1[j-1].t_arrival-o1[j].t_arrival);
		cout<<"----------------------------------------------------------------------------";
		}
		else{
		cout<<"Waiting Time\t"<<"Turnaround time\t"<<"\n";	
		cout<<(o1[j].t_wait)<<"sec\t\t\t"<<(o1[j].t_wait+o1save[j])<<" sec\n";
		avg_turn+=(o1[j].t_wait+o1save[j]);
		avg_wait+=(o1[j].t_wait);
		cout<<"----------------------------------------------------------------------------";
		}
}
for(int j=0;j<k[2];j++)
{   
    cout<<"\n\nIn Queue Q2: P"<<o2[j].p_id<<"\n";
    if(j!=0){
		cout<<"Waiting Time\t"<<"Turnaround time\t"<<"\n";
		cout<<(o2[j].t_wait-o2[j-1].t_arrival-o2[j].t_arrival)<<" sec\t\t\t"<<((o2[j].t_wait-o2[j-1].t_arrival-o2[j].t_arrival)+o2save[j])<<" sec\n";
		avg_turn+=((o2[j].t_wait-o2[j-1].t_arrival-o2[j].t_arrival)+o2save[j]);
		avg_wait+=(o2[j].t_wait-o2[j-1].t_arrival-o2[j].t_arrival);
		cout<<"----------------------------------------------------------------------------";
		}
		else{
		cout<<"Waiting Time\t"<<"Turnaround time\t"<<"\n";
		cout<<(o2[j].t_wait)<<" sec\t\t\t"<<(o2[j].t_wait+o2save[j])<<" sec\n";
		avg_turn+=(o2[j].t_wait+o2save[j]);
		avg_wait+=(o2[j].t_wait);
		cout<<"----------------------------------------------------------------------------";
		}
}
for(int j=0;j<k[3];j++)
{   
    cout<<"\n\nIn Queue Q3: P"<<o3[j].p_id<<"\n";
    if(j!=0){
    	cout<<"Waiting Time\t"<<"Turnaround time\t"<<"\n";
		cout<<(o3[j].t_wait-o3[j-1].t_arrival-o3[j].t_arrival)<<" sec\t\t\t"<<((o3[j].t_wait-o3[j-1].t_arrival-o3[j].t_arrival)+o3save[j])<<" sec\n";
		avg_turn+=((o3[j].t_wait-o3[j-1].t_arrival-o3[j].t_arrival)+o3save[j]);
		avg_wait+=(o3[j].t_wait-o3[j-1].t_arrival-o3[j].t_arrival);
		cout<<"----------------------------------------------------------------------------";
		}
		else{
			cout<<"Waiting Time\t"<<"Turnaround time\t"<<"\n";	
		cout<<(o3[j].t_wait)<<" sec\t\t\t"<<(o3[j].t_wait+o3save[j])<<" sec\n";
		avg_turn+=(o3[j].t_wait+o3save[j]);
		avg_wait+=(o3[j].t_wait);
		cout<<"----------------------------------------------------------------------------";
		}
}
cout<<"----------------------------------------------------------------------------";
cout<<"\nAverage Waiting time \t"<<"Average Turnaround time \n";
cout<<(avg_wait/n)<<" sec\t\t\t"<<(avg_turn/n)<<" sec\n";
cout<<"----------------------------------------------------------------------------";
	
	
}

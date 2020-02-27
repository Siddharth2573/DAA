
#include<stdio.h>
#include<time.h>
 
void DFS(int);
int G[10][10],visited[10],n;    
 
void main()
{
    int i,j, source;
    clock_t starttime,endtime;
    printf("Enter number of vertices:");
   	scanf("%d",&n);
 
    
	printf("\nEnter adjecency matrix of the graph:");
   		for(i=0;i<n;i++)
   		    for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
 
    
   for(i=0;i<n;i++)
        visited[i]=0;

    printf("Enter source vertex: between 0 to n-1\n");
    scanf("%d",&source);
ṇ
    starttime=clock();	
    DFS(source);
    endtime=clock();	
    
    printf("\nTime for execution= %f seconds\n", (float)(endtime-starttime)/CLOCKS_PER_SEC);
	
    printf("reachable vertices from source %d are :\n", source);    
    for(i=0;i<n;i++)
	if(i!=source&& visited[i])
		printf("%d\n",i);
}
 
void DFS(int i)
{
        int j;
	
   	
	visited[i]=1;
	
	for(j=0;j<n;j++)
      	    if(!visited[j]&&G[i][j]==1)
	    {
		printf("%d--->%d\n",i,j);
            	DFS(j);
	    }
}







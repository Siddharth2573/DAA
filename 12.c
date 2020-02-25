#include<stdio.h>
#include<time.h>
int main()
{
    int a[10][10];	
    int i,j,k,n;	
   double clk;
   clock_t starttime,endtime;
   printf("Enter  number of vertices:");
   scanf("%d",&n);

   printf("Enter the adjacency matrix");
   for(i=0;i<n;i++)
         for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
         
printf("The adjacency matrix of the digraph is:\n");   
for(i=0;i<n;i++)
       {
          for(j=0;j<n;j++)
               printf("%d",a[i][j]);
           printf("\n");
        }

starttime=clock();

for(k=0;k<n;k++)
          for(i=0;i<n;i++)
                      for(j=0;j<n;j++)
                               a[i][j]=a[i][j]||(a[i][k]&&a[k][j]);
                     
 endtime=clock();

printf("The transitive closure of the digraph is:\n");   
for(i=0;i<n;i++)
       {
          for(j=0;j<n;j++)
               printf("%d",a[i][j]);
           printf("\n");
        }
   clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
   printf("The runtime is %f",clk);
}
#include <stdio.h>
typedef struct Line line;
struct Line
{ 
	int point_1;
	int point_2;
};
 
int main(int argc, char const *argv[])
{
	int m,n;
	printf("Number of vertices\n");
	scanf("%d",&n);
	printf("Number of edges\n");
	scanf("%d",&m);
	line L[n];
	for (int i = 0; i < m; i++)
	{
		printf("point_1(%d):", i + 1);
		scanf("%d", &L[i].point_1);
		printf("point_2(%d):", i + 1);
		scanf("%d", &L[i].point_2);
	}
	
	int result[n + 1][n + 1];
	for (int i = 0; i <= n; i++)
	{
		result[0][i]=i;
		result[i][0]=i;
	}
	for (int i = 1; i <= n; i++)
	{
		for ( int j = 1; j <= n ; j++)
		{
			result[i][j]=0;
		}	
	}
	for (int i = 0; i < m; i++)
	{
		result[L[i].point_1][L[i].point_2]=1;
        result[L[i].point_2][L[i].point_1]=1;
	}
	for (int i = 0; i <=n ; i++)
	{    printf("\n");
		for (int j = 0; j <= n; j++)
		{
			printf("%d ",result[i][j]);
		}
		
	}
    int dot[n+1];
    char success;
    int count=0;
    int flag=0;
    for (int i = 1; i <=n ; i++) {dot[i]=0;}
    dot[1]=1;
    count++;
    do
    {
       success=1;
       for (int i = 1; i <=n; i++)
       {
          if (dot[i]==1)
          {
              for (int j = 1; j <=n ; j++)
              {
                 if (dot[j]==0 && result[i][j]>0)
                 {
                     dot[j]=1;
                     success=0;
                     count++;
                     if(count==n) {flag=1;break;}
                 }
                 
              }
              
          }
       }
       
    } while (success==0);
    if (flag==1)
    {
        printf("\nGraph connected. ");
    }
    else
    {
        printf("\nGraph disconnected. ");
    }
    FILE *f;
	f = fopen("graph.dot", "w");
	fprintf(f, "graph phong {\n");
	for(int i = 0; i < m; i++)
	{
		fprintf(f, "%d--%d\n", L[i].point_1, L[i].point_2);
	}
	fprintf(f, "}");
	fclose(f);
	return 0;

}
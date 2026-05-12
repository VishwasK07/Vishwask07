#include<stdio.h>
#define MAX 10
#define INF 9999
int main(){
    int n,i,j;
    int x,y;
    int cost[MAX][MAX];
    int visited[MAX]={0};
    int edges=0;
    int mincost=0;
    printf("Enter number of cities:\n");
    scanf("%d",&n);
    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0){
                cost[i][j]=INF;
            }
        }
    }
    visited[0]=1;
    printf("Optimal power grid connection:\n");
    while (edges<n-1)
    {
        int min=INF;
        for(i=0;i<n;i++){
        
            if(visited[i]){
                for(j=0;j<n;j++){
                if(!visited[j]&&cost[i][j]<min){
                    min=cost[i][j];
                    x=i;
                    y=j;
                }  
                }
            }
        
    }
    printf("Connect city%d->city%d,cost=%d\n",x,y,min);
    mincost+=min;
    visited[y]=1;
    edges++;
}
printf("\n Total power grid cost=%d\n",mincost);
return 0;
    

}
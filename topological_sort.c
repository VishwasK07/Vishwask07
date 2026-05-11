#include<stdio.h>
#define MAX 20

int queue[MAX], front=-1, rear=-1;

void enqueue(int v){
    queue[++rear] = v;
}

int dequeue(){
    return queue[++front];
}

int isEmpty(){
    return front == rear;
}

int main(){

    int n;
    int adj[MAX][MAX], indegree[MAX]={0};

    printf("Enter number of vertices:\n");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            scanf("%d",&adj[i][j]);

            if(adj[i][j]==1){
                indegree[j]++;
            }
        }
    }   

    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            enqueue(i);
        }
    }

    printf("\nTopological order of tasks:\n");

    while(!isEmpty()){

        int u = dequeue();

        printf("Task %d ", u);

        for(int i=0;i<n;i++){

            if(adj[u][i]==1){

                indegree[i]--;

                if(indegree[i]==0){
                    enqueue(i);
                }
            }
        }
    }

    return 0;
}
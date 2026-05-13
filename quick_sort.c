#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    int temp;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }

    }
    temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return i+1;
}
void quickSort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
int main(){
    int n,i;
    clock_t start,end;
    printf("Enter number of customer orders:\n");
    scanf("%d",&n);
    int orders[n];
    srand(time(0));
    printf("Generated order IDs:\n");
    for(i=0;i<n;i++){
        orders[i]=rand()%10000;
        printf("%d ",orders[i]);

    }
    start=clock();
    quickSort(orders,0,n-1);
    end=clock();
    printf("\nSorted order IDs:\n");
    for(i=0;i<n;i++){
        printf("%d ",orders[i]);
    }
    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nExecution time:%f seconds\n",time_taken);
    return 0;
}


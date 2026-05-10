#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[],int l,int m,int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[5000],R[5000];
    for(int i=0;i<n1;i++){
        L[i]=arr[l+i];
        for (int j = 0; j < n2; j++){
        
            R[j]=arr[m+1+j];
        }
    }
    i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            arr[k++]=L[i++];
        }
        else{
            arr[k++]=R[j++];
        }
    }
    while(i<n1){
        arr[k++]=L[i++];
    }
    while(j<n2){
        arr[k++]=R[j++];
    }
}
void mergeSort(int arr[],int l,int r){
    if(l<r){
    int m=(l+r)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
    }
}
int main(){
    int n,arr[10000];
    clock_t start,end;
    printf("Enter size:\n");
    scanf("%d",&n);
    srand(time(0));
    for(int i=0;i<n;i++)
        arr[i]=rand()%10000;
    printf("Generated ID's:\n");
        for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    start=clock();
    mergeSort(arr,0,n-1);
    end=clock();
    printf("\n Sorted Id's:\n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    double t= ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nExecution time:%f seconds\n",t);
    return 0;
}

    

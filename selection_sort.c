#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int arr[100000];
int n; 
int main(){
printf("Enter number of elements:\n");
scanf("%d",&n);
srand(time(0));
printf("Generated USN:\n");
for(int i=0;i<n;i++){
    arr[i]=rand()%1000;
    printf("1RN24CD%03d ",arr[i]);
}
clock_t start,end;
start=clock();
for(int i=0;i<n-i;i++){
    int min = i;
    for(int j=i+1;j<n;j++){
        if(arr[i]<arr[min]){
             min = j;
        }
    }
    int temp = arr[i];
arr[i] = arr[min];
arr[min] = temp;
}
end = clock();
printf("Sorted Array:\n");
for(int i=0;i<n;i++){
    printf("1RN24CD%03d ",arr[i]);
}
double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
printf("\nExecution time:%f seconds\n",time_taken);
return 0;
}



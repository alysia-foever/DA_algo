/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>
#define swap(a,b) (a = a^b,b=a^b,a=a^b)
#define ElemType int
void insertSort(ElemType num[],int size){
    for(int i = 1;i < size;++i){
        int key = num[i];
        int j = i - 1;
        while((j >= 0 ) && (num[j] > key)){
            //Compare and move at the same time
            num[j+1] = num[j];
            --j; 
        }
        //Insert to the blank
        num[j+1] = key;
            
    }

}
int getPivot(ElemType num[],int low,int high){
    int mid = (low + high) / 2;
    int a[3] = {num[low],num[mid],num[high]};
    insertSort(num,3);
    num[low] = a[1],num[mid] = a[0], num[high] = a[2];
    return num[low];
}
int Partition(ElemType num[],int low,int high){
    ElemType pivot = getPivot(num,low,high);
    //Move the middle number of num[low],num[mid],num[high] to num[low](pivot hole)
    int i = low, j = high;
    //Fill the hole
    while(i < j){
     while(i < j && num[j] >= pivot)--j;
        num[i] = num[j];

     while(i < j && num[i] <= pivot)++i;
        num[j] = num[i];
    }
    num[i] = pivot;
    return i; 
}

void quicksort(ElemType num[],int low,int high){
    if(low >= high)return;
    int index = Partition(num,low,high);
    quicksort(num,low,index - 1),quicksort(num,index + 1,high);
}

int main(){
    int a[100];
    int n;
    while(scanf("%d",&n)==1){
        for(int i=0;i<n;++i)scanf("%d",&a[i]);
        quicksort(a,0,n-1);
        for(int i=0;i<n;++i)printf("%d ",a[i]);
    }
}











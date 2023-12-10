#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int findPivot(int *nums,int low,int high){
    int mid = (low + high)/2;
    int a[3] = {nums[low],nums[mid],nums[high]};
    for(int i = 1;i < 3;++i){
        int key = a[i];
        int j = i - 1;
        while( (j >= 0) && a[j] > key){
            a[j+1] = a[j];
            --j;
        }
        //Jump into the hole
        a[j+1] = key;
    }
    nums[low] = a[1],nums[mid] = a[0], nums[high] = a[2];
    return nums[low];
}
int partition(int*nums,int low,int high,int k,int numsSize){
    if(low == high) return nums[low];
    int pivot = findPivot(nums,low,high);
    int i = low, j =high;
    while(i < j){
        while( i < j && nums[j] >= pivot)--j;
        nums[i] = nums[j];
        while( i < j && nums[i] <= pivot)++i;
        nums[j] = nums[i];
    }
    nums[i] = pivot;
    if(k == numsSize - i)return nums[i];
    else if(k > numsSize - i)return partition(nums,low,i-1,k,numsSize);
    else return partition(nums,i+1,high,k,numsSize);
}
int findKthLargest(int* nums, int numsSize, int k) {
    return partition(nums,0,numsSize - 1, k, numsSize);
}

int main(){
    int nums[100];
    int n,k;
    while(scanf("%d%d",&n,&k)==2){
        for(int i=0;i<n;++i)scanf("%d",&nums[i]);
        printf("%d",findKthLargest(nums,n,k));
    }
}
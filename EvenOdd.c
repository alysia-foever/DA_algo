/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>
#define swap(a,b) (a = a^b,b=a^b,a=a^b)
int searchNextOdd(int*nums,int ptr,int numsSize){
    while(ptr < numsSize)
        if(nums[++ptr] % 2)break;
    return ptr;    
}
int searchNextEven(int *nums,int ptr){
    while(ptr >=0)
        if(nums[--ptr] %2 == 0)break;
    return ptr;
}
int* sortArrayByParity(int* nums, int numsSize) {
    int i = searchNextOdd(nums,-1,numsSize),j = searchNextEven(nums,numsSize);
    while(i < j){
       swap(nums[i],nums[j]);
        i = searchNextOdd(nums,i,numsSize);
        j = searchNextEven(nums,j);
    }
    return nums;
}


int main(){
    int n;
    int nums[100];
    while(scanf("%d",&n)==1){
    for(int i=0;i<n;++i)scanf("%d",&nums[i]);
    sortArrayByParity(nums,n);
    for(int i=0;i<n;++i)printf("%d", nums[i]);
    }
}











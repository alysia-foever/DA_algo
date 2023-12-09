#define _CRT_SECURE_NO_WARNINGS
#define swap(a,b) (a=a^b,b=a^b,a=a^b)
#include <stdio.h>
#include<stdlib.h>

void DoubleEndBubble(int arr[],int size){
int left = 0,right = size - 1;

while(left < right){

    for(int i=left;i<=right;++i){
        //Stone to bottom
        if(i!= right && arr[i] > arr[i+1])swap(arr[i],arr[i+1]);
    }
    --right;

    for(int i=right;i>=left;--i){
        //Bubble to top
        if(i!=left && arr[i]<arr[i-1])swap(arr[i],arr[i-1]);
    }

    ++left;
}

}

int main(){
int num[100];
int n;
while(scanf("%d",&n)==1){
for(int i=0;i<n;++i)scanf("%d",&num[i]);
DoubleEndBubble(num,n);    

for(int i=0;i<n;++i)printf("%d ",num[i]);
}

}














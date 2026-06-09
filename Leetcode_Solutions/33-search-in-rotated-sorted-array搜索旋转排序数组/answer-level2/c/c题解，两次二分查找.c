```
执行结果：通过
显示详情执行用时 :4 ms, 在所有 C 提交中击败了91.40%的用户
内存消耗 :7.2 MB, 在所有 C 提交中击败了69.08%的用户
```
## 两次二分查找
* 第一次，找转折点，即最小值
* 第二次，看target是在最小值的左边或者右面，无论左边还是右边，都是递增数列
## 怎么找到最小的值?
```c
void findMin(int* nums, int numsSize,int *addr){
  int *left=nums;
  int *right=nums+numsSize-1;
  while(left<right){
    int *mid=left+(right-left)/2;
    if(*mid>*right){
      left=mid+1; //care
    }else{
      right=mid; //care
    }
  }
  *addr=right-nums;
}
```
## 全部代码如下
```c
#include <stdio.h>
void findMin(int* nums, int numsSize,int *addr){
  int *left=nums;
  int *right=nums+numsSize-1;
  while(left<right){
    int *mid=left+(right-left)/2;
    if(*mid>*right){
      left=mid+1; //care
    }else{
      right=mid;  //care
    }
  }
  *addr=right-nums;
}
int search(int* nums, int numsSize, int target){
  if(numsSize==0){
    return -1;
  }
  int addr;
  findMin(nums,numsSize,&addr);
  int *left=nums;
  int *right=nums+numsSize-1;
  if(*left>target){
    left=nums+addr;
  }else if(addr>0 && *left<=target){
    right=nums+addr-1;  //care
  }else{
      
  }
  while(left<right){
    int *mid=left+(right-left)/2;
    if(*mid==target){
      return mid-nums;
    }else if(*mid<target){
      left=mid+1;
    }else{
      right=mid-1;
    }
  }
  if(*left==target){
    return left-nums;
  }else{
    return -1;
  }
}
```
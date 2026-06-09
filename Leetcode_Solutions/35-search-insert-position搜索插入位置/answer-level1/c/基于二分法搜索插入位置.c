思路：二分法查找，再寻找插入位置
```c
int searchInsert(int* nums, int numsSize, int target){
    int middle = 0,left = 0,right = numsSize-1;
    while(right-left>1){
        middle = (left+right)/2;
        if(nums[middle]<target)left = middle;
        else if(nums[middle]>target)right = middle;
        else break;
    }
    for(middle = left;middle<right+1;middle++)
        if(nums[middle]>=target)break;
    return middle;
}
```
//改良版 思路：直接二分法
```c
int searchInsert(int* nums, int numsSize, int target){
     int middle = 0,left = 0,right = numsSize-1;
     while(right>=left){
         middle = (left+right)/2;
         if(nums[middle]<target)left = middle+1;
         else right = middle-1;
     }
     return left;
 }
```

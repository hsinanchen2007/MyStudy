解法一：暴力就完事了
```c
int searchInsert(int* nums, int numsSize, int target){
    int i = 0;
    while(i<numsSize && nums[i]<target){
       i++;
    }
    return i;
}
``` 

解法二：折半查找
```
int searchInsert(int* nums, int numsSize, int target){
    int low=0,high=numsSize-1,mid;
    while(low<=high){
        mid = (low+high)/2;
        if(nums[mid]>target){
            high = mid-1;
        }else if(nums[mid]<target){
            low = mid+1;
        }else{
            return mid;
        }
    }
    return low;
}
```

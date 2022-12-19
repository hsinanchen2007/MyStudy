### 解题思路
二分查找目标值

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    int low, mid, high;
    low = 0;
    high = numsSize - 1;
    
    while(low <= high){
        mid = low + (high - low)/2;
        if(target == nums[mid]){
            return mid;
        }
        else if(target > nums[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }        
    }
    return low;
    
}
```
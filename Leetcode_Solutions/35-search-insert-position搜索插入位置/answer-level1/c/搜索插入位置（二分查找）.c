### 解题思路
利用二分查找，时间复杂度O(log(n))。
至于更牛的2%高人的方法，后面一定要尝试下。

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){

    if(target <= nums[0])
        return 0;
    if(target > nums[numsSize-1])
        return numsSize;
    
    int low = 0;
    int high = numsSize -1;
    int middle;
    while((high-low)>1)
    {
        middle = (low + high)/2;
        if(nums[middle] > target)
            high = middle;
        else if(nums[middle] < target)
            low = middle;
        else
            return middle;
    }
    return low+1;
}
```
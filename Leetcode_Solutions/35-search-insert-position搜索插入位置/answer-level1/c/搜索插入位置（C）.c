### 解题思路
折半查找，没什么难度。

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    if(0 == numsSize)
        return 0;
    int low = 0, high = numsSize - 1, mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(target == nums[mid])
            return mid;
        else if(target < nums[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}
```
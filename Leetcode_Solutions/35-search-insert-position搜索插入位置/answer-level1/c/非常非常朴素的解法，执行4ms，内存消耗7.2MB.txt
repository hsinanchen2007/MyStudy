### 解题思路
iterate through the array. During each iteration, check if the element equates the target and if the target is smaller than the current element. Return the index i if any of this two ocassion happens: the target is found; it's no longer possible to find the target in the array. Under most cases, this will work except the target is greater than every elements in the array. In that case we return the numsSize, which is just the right place for the target to be inserted.

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    for(int i = 0;i < numsSize; i++){
        if(target == nums[i]){
            return i;
        }
        if(target < nums[i]){
            return i;
        }
    }
    return numsSize;
}
```
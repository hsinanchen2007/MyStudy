### 解题思路
遍历数组，如果数组元素大于等于目标值，返回当前索引，遍历结束的话返回当前数组长度

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    for(int i = 0; i < numsSize;i++){
        if(nums[i] >= target){
            return i;
        }
    }

    return numsSize;
}
```
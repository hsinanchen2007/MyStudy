### 解题思路
此处撰写解题思路
其中就是一个排序问题。或许可以用二分法

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    int i = 0;

    for(i = 0; i < numsSize; i ++)
    {
        if(target <= nums[i])
        {
            return i;
        }
    }

    return i;
}
```
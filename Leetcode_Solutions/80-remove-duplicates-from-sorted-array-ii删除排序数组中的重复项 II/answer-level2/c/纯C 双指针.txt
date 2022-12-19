### 解题思路
双指针 快慢指针

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    if (numsSize <= 2)
    {
        return numsSize;
    }

    int slow = 2;
    int fast = 2;

    for (; fast <= numsSize - 1; fast++)
    {
        if (!(nums[slow - 2] == nums[slow - 1] && nums[slow - 1] == nums[fast]))
        {
            nums[slow++] = nums[fast];
        }
    }

    return slow;
}
```
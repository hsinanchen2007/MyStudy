### 解题思路
快慢指针（下标）
### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    if (numsSize <= 1) 
    {
        return numsSize;
    }

    int size = 0;
    int slow = 0;
    int fast = 0;

    for (slow = 0; slow <= numsSize - 2; slow = fast) // 慢的到倒数第二个位置就行了
    {
        for (fast = slow + 1; fast <= numsSize - 1; fast++)
        {
            if (nums[slow] != nums[fast])
            {
                break;
            }
        }

        if (fast <= numsSize - 1) // 排除最后两个是相等的情况
        {
            nums[++size] = nums[fast];
        }
    }

    return size + 1;
}
```
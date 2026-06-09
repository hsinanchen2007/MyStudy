### 解题思路
双指针 快慢指针

### 代码

```c
int jump(int* nums, int numsSize){
    if (NULL == nums || 0 == numsSize)
    {
        return 0;
    }

    int slow = 0;
    int fast = 0;
    int max = 0;
    int step = 0;

    for (slow = 0; slow <= fast; )
    {
        if (fast >= numsSize - 1)
        {
            return step;
        }

        for (; slow <= fast; slow++)
        {
            max = max > slow + nums[slow] ? max : slow + nums[slow];
        }

        fast = max;
        step++;
    }

    return 0;
}
```
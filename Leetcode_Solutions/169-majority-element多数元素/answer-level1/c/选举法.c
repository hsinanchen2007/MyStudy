### 解题思路
1. 设置一个计数，于基数比较遇到相同的则加一，否则减一，减到负数时将此数重置
2. 因为总数总是大于一般的，所以当总数的计数肯定大于0

### 代码

```c
int majorityElement(int* nums, int numsSize){
    int i, num = nums[0], count = 0;
    for (i = 1; i < numsSize; i++)
    {
        count += (num == nums[i]) ? 1 : -1;
        if (count < 0) 
        {
            num = nums[i];
            count = 0;
        }
    }
    return num;
}
```
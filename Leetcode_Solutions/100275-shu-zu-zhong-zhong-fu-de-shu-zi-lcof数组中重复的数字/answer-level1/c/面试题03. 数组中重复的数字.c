### 解题思路
遍历数组，依次记录每个数字出现的次数，直到某数字出现次数大于等于2时，返回该值。该算法只是用于所有数字都在 0～n-1 的范围内
### 代码

```c
int findRepeatNumber(int* nums, int numsSize){
    int i;
    int iTmp;
    int aiNum[100000] = {0};

    for (i = 0; i < numsSize; i++)
    {
        iTmp = nums[i];
        aiNum[iTmp]++;
        if(2 <= aiNum[iTmp])
        {
            return iTmp;
        }
    }
    return 0;
}
```
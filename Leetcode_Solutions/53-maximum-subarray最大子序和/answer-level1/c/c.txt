### 解题思路
此处撰写解题思路
1、循环i，找到i最大值，然后最终找到一个max_num

### 代码

```c
int maxSubArray(int* nums, int numsSize){
    int max = nums[0];
    int tmp = nums[0], tmp_max = nums[0];
    int i = 0, j = 0;

    for(i = 1; i < numsSize; i++)
    {
        tmp_max = tmp = nums[i];

        for(j = (i - 1); j >= 0; j--)
        {
            tmp += nums[j];

            if(tmp > tmp_max)
            {
                tmp_max = tmp;
            }
        }

        if(tmp_max > max)
        {
            max = tmp_max;
        }
    }

    return max;
}
```
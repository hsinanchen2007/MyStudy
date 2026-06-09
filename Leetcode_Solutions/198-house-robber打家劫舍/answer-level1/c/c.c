### 解题思路
此处撰写解题思路
1、本题采用动态规划思想，即max(i) = max{max(i - 3), max(i - 2)} + nums[i];

### 代码

```c
int rob(int* nums, int numsSize){
    int a[3] = {0};
    int tmp = 0;
    int i;
    int max = 0;

    for (i = 0; i < numsSize; i++)
    {
        if(a[i % 3] > a[(i + 1) % 3])
        {
            a[i % 3] = a[i % 3] + nums[i];
        }
        else
        {
            a[i % 3] = a[(i + 1) % 3] + nums[i];
        }
    }

    for (i = 0; i < 3; i++)
    {
        max = (a[i] > max) ? a[i]: max;
    }

    return max;
}
```
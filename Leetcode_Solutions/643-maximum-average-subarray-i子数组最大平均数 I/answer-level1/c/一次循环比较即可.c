### 解题思路
此处撰写解题思路

### 代码

```c
double findMaxAverage(int* nums, int numsSize, int k){
    int i;
    double sum = 0,max;

    for (i = 0; i < k; i++)
        sum += nums[i];
    if (numsSize == k)
        return sum / k;
    max = sum;
    for (i = 1; i <= numsSize&&(i+k-1)<numsSize; i++)
    {
        sum = sum - nums[i - 1] + nums[i + k - 1];
        max = sum > max ? sum : max;
        
    }
    return max / k;
}
```
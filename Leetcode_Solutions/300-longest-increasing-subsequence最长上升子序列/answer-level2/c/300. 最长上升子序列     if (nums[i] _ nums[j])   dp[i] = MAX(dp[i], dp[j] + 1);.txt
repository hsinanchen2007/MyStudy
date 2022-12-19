### 解题思路


给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。


### 代码

```c
#define MAX(a,b) ((a)>(b)?(a):(b))

int lengthOfLIS(int* nums, int numsSize) {
    int dp[10000] = {0};
    int i, j, max = 1;

    if (numsSize == 0)
        return 0;

    dp[0] = 1;
    for (i = 1; i < numsSize; i++) {
        dp[i] = 1;
        for (j = 0; j < i; j++) {
            if (nums[i] > nums[j])
                dp[i] = MAX(dp[i], dp[j] + 1);
        }
        max = MAX(dp[i], max);
    }
    
    return max;
}
```
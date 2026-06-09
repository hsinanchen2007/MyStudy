首先要明确DP的主要思想：即使用已有的结果去更新下一步的结果。
   因此在解答本题时，首先需要线性扫描整个输入的数组，并且不断累加，即：dp[i] = dp[i-1] + nums[i]，其中dp代表前面i-1步的累积和。可以看到，如果此时dp[i-1] < 0，则dp[i]一定会比nums[i]小，所以从i往后的子数列的和一定大于从i之前的元素开始的子数列的和，因此此时将dp[i]重新赋值为nums[i]，再继续扫描下一个元素。

```
def maxSubArray(nums):
    n = len(nums)
    if n == 1:
        return nums[0]
    else:
        dp = nums[0]
        result = dp
        i = 1
        while i < n:
            dp = max(dp, 0) + nums[i]
            result = max(result, dp)
            i += 1
        return result
```





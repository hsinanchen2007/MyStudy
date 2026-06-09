## 思路:

**思路一:** 动态规划

当前面的总和是负数的,加上去一定会使总和减小,不如从自己重新开始.

例如,`[-2,1,-3,4]`

`1`就不需要加前面`-2`,自己可以重新开始.

**思路二:**

`sum(i,j) = sum(0,j) - sum(0,i)`

我们只要记录前`i`总和最小值就可以了!

上面时间复杂度都是:$O(n)$


## 代码:

思路一:



```python [1]
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0] * n
        dp[0] = nums[0]
        res = nums[0]
        for i in range(1, n):
            dp[i] = max(dp[i-1] + nums[i], nums[i])
            res = max(dp[i], res)
        return res
```


```java [1]
class Solution {
    public int maxSubArray(int[] nums) {
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.length; i++) {
            dp[i] = Math.max(dp[i-1]+nums[i], nums[i]);
            res = Math.max(res, dp[i]);
        }
        return res;  
    }
}
```

思路二:



```python [2]
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        cur_sum = 0
        min_sum = 0
        res = float("-inf")
        for num in nums:
            cur_sum += num
            res = max(res, cur_sum - min_sum)
            min_sum = min(min_sum, cur_sum)
        return res
```



```java [2]
class Solution {
    public int maxSubArray(int[] nums) {
        int all_sum = 0;
        int min_sum = 0;
        int res = Integer.MIN_VALUE;
        for (int num : nums) {
            all_sum += num;
            res = Math.max(res, all_sum - min_sum);
            min_sum = Math.min(min_sum, all_sum);
        }
        return res;   
    }
}
```












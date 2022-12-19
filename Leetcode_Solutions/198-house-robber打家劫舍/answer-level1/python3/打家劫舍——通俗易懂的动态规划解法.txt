思路：
- 先考虑递归，从上到下去解，但是，递归会导致多个重复子问题，时间复杂度很高
- 因此考虑动态规划，对于动态规划，首先自己从最基本的一步步去推

![image.png](https://pic.leetcode-cn.com/efefdfcbffac2e70197dfc0fea26c8883e676365594de698fda9b7835fd764c0-image.png)



```python []
# O(n)
# O(n)
class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)

        dp = [[0]*2 for _ in range(n+1)]
        for i in range(1,n+1):
            #不抢时前一个抢或不抢都无所谓，取两者中的大的
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]) 
            #抢时则前一个需要不抢，加上本身抢的(dp下标是1~n，nums下标是从0~n-1，因此nums[i-1]就是第i个数值)
            dp[i][1] = dp[i-1][0]+nums[i-1]
        
        return max(dp[n][0],dp[n][1])

#O(n)
#O(1)
# 优化空间复杂度
class Solution:
    def rob(self, nums: List[int]) -> int:
        yes,no = 0,0
        for i in nums:
            no,yes = max(no,yes),i+no
        return max(no,yes)
```


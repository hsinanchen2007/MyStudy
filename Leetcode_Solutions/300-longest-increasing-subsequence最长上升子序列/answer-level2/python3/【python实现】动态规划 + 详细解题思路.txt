解题思路：
根据题意可得，最长的上升子序列可能出现在任何的位置，不适合用dfs方法做，可以考虑动态规划。
一、最优子结构
1. 假设f(1）~f(n-1)已知，如何求f(n)？
如果最后一个数被选择了，那么它将可以与前面的比它小的值nums[i]组合，增加1个子序列的长度。
并在这些值中选择一个长度最大的。
因此，递推方程可以表示为：`f(n)  = max{f(i), nums[i-1] < nums[n-1] , 1<= i <n-1} + 1`
自然地，f(n)被定义为：从nums[0]~nums[n-1]的（包含 nums[n-1]的）最长上升子序列
二、重叠子问题
根据递推方程，可以发现f(n)依赖于前面所有的值，因此，f(n-1)也会依赖前面的所有值，存在重叠的子问题。

因此满足动态规划。

时间复杂度：
需要填n-1个数，每个数需要遍历之前所有的值，因此O(n)=O(1+2+3+……+n-2) = O(n^2)

空间复杂度：
使用一维dp数组存储，因此为O(n)
```
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # 特殊情况判断
        if len(nums) <= 1:
            return len(nums)
        # 定义dp：一维列表        
        # 初始化dp：因为依赖all，所以需要全部初始化
        dp = [1] * len(nums)
        max_lis = 0

        # 自底向上填表
        for i in range(1, len(nums)):  # 从1开始
            for j in range(i): # 依赖i之前的所有值
                # 满足递推方程条件
                if nums[j] < nums[i] and dp[i] < dp[j] + 1:
                    dp[i] = dp[j] + 1  # 递推方程
                
            # 更新最大值
            max_lis = max(dp[i], max_lis)
        
        return max_lis
```
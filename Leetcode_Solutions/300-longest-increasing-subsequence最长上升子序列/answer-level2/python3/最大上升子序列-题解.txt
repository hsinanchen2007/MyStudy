### 解题思路
暴力求解思路，
- 以当前元素作结尾，往前找比它小的元素，然后比较在哪一个子序列上长度最长，记录下每一次比较的最大值；
- 序列长度使用一个数组做记录，表示以当前元素作结尾，所能达到的最大上升子序列长度；

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        lgth = len(nums)
        if lgth < 1:
            return 0

        dp = [1]*lgth
        rst = 1
        for i in range(1, lgth):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[j]+1, dp[i])
            rst = max(rst, dp[i])
        
        return rst
            
                
```
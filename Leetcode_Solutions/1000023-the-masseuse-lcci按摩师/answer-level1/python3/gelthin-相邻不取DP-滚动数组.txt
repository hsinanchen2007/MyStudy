### 解题思路
同打家劫舍题, 简单 DP 即可。童老师课程上也讲到此题。
[198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/)

官方题解一般。
然后这里可以使用滚动数组技巧，节省空间。


### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        # DP 打家劫舍题
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        DP = [0]*(n+1) # DP[0] = 0 边界条件，便于 DP[2] = nums[1]
        DP[1] = nums[0]  # nums[0] 代表第一个人
        for i in range(2,n+1):
            DP[i] = max(DP[i-1], DP[i-2]+nums[i-1])
        return DP[n]

```
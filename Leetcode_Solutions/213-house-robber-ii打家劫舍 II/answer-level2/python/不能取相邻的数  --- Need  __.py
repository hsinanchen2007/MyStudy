### 解题思路：
0. 198. 打家劫舍 一排房子（相连）
    - dp[i] = max(dp[i-1], dp[i-2] + nums[i])
    - 即，**第i个位置，仅需要考虑第i-1 和 i-2 的位置**
    - **i-2 之前什么情况，那是子问题（i-1 和 i-2）考虑的**
    - **二叉树的递归貌似也可归纳为子问题**
1. **此题是 198. 打家劫舍 的拓展版： 唯一的区别是此题中的房间是环状排列的（即首尾相接）**
    - 环状排列意味着第一个房子和最后一个房子中只能选择一个偷窃，因此可以**把此环状排列房间问题约化为两个单排排列房间子问题**：
    - 在不偷窃第一个房子的情况下（即 nums[1:]），最大金额是 p1；
    - **在不偷窃最后一个房子的情况下（即 nums[:n-1]），最大金额是 p2**
​
2. 个人的思路也是这样的，但是有一点没有想明白：
    - 在不偷窃第一个房子的情况下（即 nums[1:]），最大金额是 p1： **要是P1 的最大值，没有偷最后一家，是否需要把num[0] 加上？**
    - **加粗部分是真的“想多了”**，因为上述两种情况正好是全解。

3. [打家劫舍 II（动态规划，结构化思路，清晰题解）](https://leetcode-cn.com/problems/house-robber-ii/solution/213-da-jia-jie-she-iidong-tai-gui-hua-jie-gou-hua-/)
    - dp[i] = max(dp[i-2] + val, dp[i-1])


4. [打家劫舍 III 这个地方的所有房屋的排列类似于一棵二叉树](https://leetcode-cn.com/problems/house-robber-iii/solution/san-chong-fang-fa-jie-jue-shu-xing-dong-tai-gui-hu/)
    - 一个爷爷 + 两个儿子 + 四个孙子 如何取舍

4. [每次爬 1 或 2 个台阶，有多少种爬法](https://leetcode-cn.com/problems/climbing-stairs/)
    - dp[i] = dp[i-1] + dp[i-2]

### 代码

```python3
class Solution:
    '''
    def rob(self, nums: List[int]) -> int:
        nsize = len(nums)
        if nsize < 1:
            return 0
        if nsize < 3:
            return max(nums)
        
        dp = [0 for i in range(nsize +1)]
        dp[1] = nums[1]
        dp[2] = max(nums[2], nums[1])
        for i in range(3, nsize):
            dp[i] = max(dp[i-2]+nums[i], dp[i-1])
        

        dp2 = [0 for i in range(nsize +1)]
        dp2[0] = nums[0]
        dp2[1] = max(nums[1], nums[0])
        for i in range(2, nsize-1):
            dp2[i] = max(dp2[i-2]+nums[i], dp2[i-1])
        
        return max(dp[nsize -1], dp2[nsize -2])
    '''
    def rob(self, nums: List[int]) -> int:
        nsize = len(nums)
        if nsize < 1:
            return 0
        if nsize < 3:
            return max(nums)
        dp1 = nums[1]
        dp2 = max(nums[2],nums[1])

        for i in range(3,nsize):
            tmp = max(dp1 + nums[i], dp2)
            dp1, dp2 = dp2, tmp 
        
        dp0 = nums[0]
        dp1 = max(nums[1], nums[0])

        for i in range(2, nsize-1):
            tmp = max(dp0 + nums[i], dp1)
            dp0, dp1 = dp1, tmp 
        
        return max(dp1, dp2)


        

```
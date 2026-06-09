### 解题思路
一开始暴力解法果然超时. 
O(1) < O(logn) < O(n) < O(nlogn) < O(n^2) < O(n^3) < O(2^n)< O(n!), 因为是阶乘级别
后面参考题解写出dp
这题的难点是子问题的划分, dp[i][j]代表[i,j]之间的最大值, 但如果选i或者选j戳破时会导致边界的变化导致子问题之间有重叠依赖.
eg: 我们设戳破区间 i 到 j 间的气球我们得到的最大金币数为coin。及coin = def( i , j )。

则当我们戳破气球 k 时，两边区间的最大值分别是 def( i , k-1 ) 与 def( k+1 , j )。

此时我们发现了问题，因为戳破了气球 k ，气球数组的相邻关系发生了改变，k-1 与 k+1 原本都与 k 相邻，而 k 戳破后他们两个直接相邻了。而且先戳破 k+1 与先戳破 k-1 得到的结果将完全不同，也就是说两个子问题间发生了依赖。如果先戳破 k-1 ，则 k+1 左边的相邻气球变成了 k-2；反之 k-1 右边相邻的气球变成了 k+2 。

子问题的处理顺序将影响到每个子问题的解，这将使我们的状态转移方程极为复杂和低效，我们应当换一种划分子问题的方式，使每个子问题都是独立的。

作者：niu-you-rou
链接：https://leetcode-cn.com/problems/burst-balloons/solution/chao-xiang-xi-hui-su-dao-fen-zhi-dao-dp-by-niu-you/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

## 因此我们就约定dp[i][j]为[i,j]范围内的最大值, 但不戳破i或j
则递推方程为def( i, j ) = max { def( i , k ) + def( k , j )+nums[ i ][ j ][ k ] } | i<k<j 注意k的范围是严格小于/大于

### 代码

```python3
class Solution:
    def maxCoins(self, nums) -> int:
        # def solve(mynums, cur, tmp):
        #     l = len(mynums)
        #     left = mynums[cur-1] if cur-1>=0 else 1
        #     right = mynums[cur+1] if cur+1<l else 1
        #     cur_coin = left*mynums[cur]*right
        #     tmp += cur_coin
        #     mynums.pop(cur)
        #     res = 0
        #     if l-1==0: return tmp
        #     for i in range(l-1):
        #         res = max(res, solve(mynums[:], i, tmp))
        #     return res
        # ret = 0
        # for i in range(len(nums)):
        #     ret = max(ret, solve(nums[:], i, 0))
        # return ret
```

```
class Solution:
    def maxCoins(self, nums) -> int:
        nums = [1]+nums+[1]
        l = len(nums)
        # print(nums)
        dp = [[0]*l for _ in range(l)] # dp[i][j]为[i,j]之间的最大值, 注意这里不能选i或j去戳破, 否则子问题会有重叠
        for i in range(l-3, -1, -1): # 这点是从后往前! 要使小范围的[i,j]先被计算!!
            for j in range(i+2, l):
                for k in range(i+1, j):
                    dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j])
        return dp[0][-1] 
```
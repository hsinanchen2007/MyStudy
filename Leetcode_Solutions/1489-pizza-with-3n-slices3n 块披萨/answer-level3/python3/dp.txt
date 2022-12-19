### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/efb674ccdeeedf3e0eef982c63f5365ae57a2886518d3d2aab14e02a5fab84c5-image.png)

讨论区关于动态规划的想法，就是求不相邻子序列的最大和。dp[i][j]标识slices[:j+1]中i个不相邻的数组成子序列的最大和。
递推公式为dp[i][j] = max([max(dp[i-1][:j-1])+slices[j]] + dp[i][:j]),注意下边界就可以了。

### 代码

```python3
class Solution:
    def maxSizeSlices(self, slices: List[int]) -> int:
        def max_not_besize(slices):
            dp = []
            import math
            for i in range(math.ceil(len(slices)/3)):
                dp.append([0]*len(slices))
            dp[0][0] = slices[0]
            for i in range(1, len(dp)):
                dp[i][0] = 0
            for i in range(len(dp)):
                for j in range(1, len(dp[0])):
                    if i>j/2:
                        continue
                    if j==1:
                        dp[i][j] = max(dp[i][j], slices[j])
                    else:
                        dp[i][j] = max(dp[i-1][:j-1]) + slices[j]
                    tmp = max(dp[i][:j])
                    dp[i][j] = max(dp[i][j], tmp)
            print(dp)
            return dp[-1][-1]
        
        tmp1 = max_not_besize(slices[:-1])
        tmp2 = max_not_besize(slices[1:])
        return max(tmp1, tmp2)
```
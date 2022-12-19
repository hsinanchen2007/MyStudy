### 解题思路
dp[i] = min(dp[i-jXj]) + 1
j < i/2+1
每次更新dp[i] = dp[i-1]
然后寻找dp[i-jXj]中的最小值
方便理解本题dp[0]空间没有用到
dp[i]表示数字i最少可以由多少个平方数之和组成

吐槽一下，发布题解为什么还要强制绑定手机号！！！
![捕获1.PNG](https://pic.leetcode-cn.com/7a571157c1be3f98b863d3cff96d1ac6e1a2ce07a4db80af84e62e003cda4c8c-%E6%8D%95%E8%8E%B71.PNG)


### 代码

```python3
class Solution:
    def numSquares(self, n: int) -> int:
        dp = [1 for _ in range(n+1)]
        for i in range(2,n+1):
            # 寻找dp[j]的最小值
            min_val = dp[i-1]
            for j in range(1,int(i/2)+1):
                if i-j*j < 0:
                    break
                elif i == j*j:
                    min_val = 0
                    break
                # i-j*j>0的情况
                if dp[i-j*j] < min_val:
                    min_val = dp[i-j*j]
            dp[i] = min_val + 1

        return dp[-1]
```
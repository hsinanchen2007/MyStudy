### 解题思路
动态规划

### 代码

```python
class Solution(object):
    def countBits(self, num):
        #dp[i]表示当nums = i时，转换成二进制数里面1的个数
        dp = [0] * (num + 1)
        for i in range(1,num+1):
            int_i = int(i // 2)
            mod_i = i % 2
            dp[i] = dp[int_i] + mod_i
        return dp
```
一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 关注交流。

### 解题思路
动态规划：
```
dp[i] = dp[i-1] + p[i]   # if i != 0 and dp[i-1] > 0
dp[i] = p[i]             # if i == 0 or dp[i-1] < 0
```

### 代码

```python
class Solution(object):
    def maxSubArray(self, array):
        max = array[0]
        dp = [0] * (len(array) + 1)
        dp[0] = array[0]
        for i in range(1, len(array)):
            if dp[i-1] < 0:
                dp[i] = array[i]
            else:
                dp[i] = array[i] + dp[i-1]
            if dp[i] > max:
                max = dp[i]
        return max
```
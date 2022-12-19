### 解题思路
见代码

### 代码

```python3
class Solution:

    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n>10:                       # 大于10必定不可能
            return 0
        dp = list()
        dp.append(1)                   # 我也不知道为啥是1, 反正人家说是1就是1吧无所谓
        dp.append(10)                  # 1个数的时候10个不重复的
        for i in range(2, n + 1):
            temp = 9                   # -\
            for j in range(i-1):       # --> 两个数以上, 就是第一个数9种选择(没0), 第二个9种
                temp *= (9 - j)        # --> 第三个8种, 依次类推
            temp += dp[i-1]            # -/
            dp.append(temp)
        return dp[n]
```
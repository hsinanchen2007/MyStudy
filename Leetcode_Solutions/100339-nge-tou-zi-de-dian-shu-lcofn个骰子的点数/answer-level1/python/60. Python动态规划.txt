### 解题思路
递推式很容易想到，因为n个筛子的组合方法可以在n - 1个筛子的组合方法的基础上获得。我们定义dp[i][j]为使用i + 1个筛子，组合成j + 1一共有多少种方法。下面的实现是使用了空间优化的方法。

### 代码

```python3
class Solution:
    def twoSum(self, n: int) -> List[float]:
        if n == 0:
            return []
        dp = [[0] * (6 * n) for _ in range(2)]
        for i in range(6):
            dp[0][i] = 1
        for i in range(1, n):
            for j in range(i, 6 * (i + 1)): # 注意这里一定要从i开始循环
                sum_num = 0
                for k in range(1, 7):
                    if j - k >= i - 1:
                        sum_num += dp[(i - 1) % 2][j - k]
                dp[i % 2][j] = sum_num
        res = dp[(n - 1) % 2][n - 1:]
        sum_num = sum(res)
        return list(map(lambda x: x / sum_num, res))
```
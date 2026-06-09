![image.png](https://pic.leetcode-cn.com/266423890eeedf08b3b72db9c91c295a511f8ad1b35fb78800c058daa8a3da54-image.png)

d 为动态规划记录数组:

d[i] 代表，最多 i 元钱时可兑换的分配方案数量;

d[0] 时为初始条件，表示0元可以用0元兑换1次，所以 d[0] = 1。

d[i - c] 中，c 代表当前面值，d[i - c] 表示 i - c 元钱所有分配方案之和，d[i] 分配方案应该等于所有 d[i - c] 分配方案之和，这样就可以快速的计算出 d[amount] 的和了。

具体可以在网上搜索背包九讲、01背包、完全背包，会有更直观的图文解释。

```py
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        d = [1] + [0] * amount
        for c in coins:
            for i in range(c, amount + 1):
                d[i] += d[i - c]
        return d[amount]
```
```py
币种/i元/动规数组变化
1 1 [1, 1, 0, 0, 0, 0]
1 2 [1, 1, 1, 0, 0, 0]
1 3 [1, 1, 1, 1, 0, 0]
1 4 [1, 1, 1, 1, 1, 0]
1 5 [1, 1, 1, 1, 1, 1]
2 2 [1, 1, 2, 1, 1, 1]
2 3 [1, 1, 2, 2, 1, 1]
2 4 [1, 1, 2, 2, 3, 1]
2 5 [1, 1, 2, 2, 3, 3]
5 5 [1, 1, 2, 2, 3, 4]
```

### 解题思路
总结：相当于找出逆序对相差最大的一对数。
解法一：利用暴力解法时间复杂度为O(N^2)，时间爆了。
解法二：
两两相减，后减前，然后求连续的累计最大值

![image.png](https://pic.leetcode-cn.com/5d370c2c56a99e86080aa9f1fbdcc74e324740dcf7596d79902251979315c462-image.png)

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        last_value = 0
        now_value = 0
        for x in range(1, len(prices)):
            prices[x-1] = prices[x]-prices[x-1]
        for j in range(0, len(prices)-1):
            if now_value + prices[j] <= prices[j]:
                now_value = prices[j]
            else:
                now_value = now_value + prices[j]
            if now_value > last_value:
                last_value = now_value
        return last_value

```
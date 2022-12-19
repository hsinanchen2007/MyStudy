这一题刚开始想的是递归求解，无非就是固定首尾指针，不是首指针往右边移，就是尾指针往左边移。所以写两个递归式即可得出答案。


代码如下：
```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # 定义获取的最大利润
        max_profit = 0
        if len(prices) <= 1:
            return max_profit

        def back(start, end, max_profit):
            if start >= end:
                return max_profit
            profit = prices[end] - prices[start]
            max_profit = back(start+1, end, max(max_profit, profit))
            max_profit = back(start, end-1, max(max_profit, profit))
            return max_profit
        return back(0, len(prices)-1, 0)


if __name__ == "__main__":
    prices = [2, 1, 4]
    max_profit = Solution().maxProfit(prices)
    print(max_profit)
```
但可气的是TLE了，既然递归行不通，那就只能是老老实实的通过遍历数组来找出答案了。

这一题其实也和前面的接雨水题目很类似，就是要找到符合题意的“相对”最大值和最小值，只不过本题中还有一个限制就是：最小值一定要在最大值的左边。因为考虑到收益问题，所以这题就不能是一开始就固定首尾指针了，而是先从左至右找到一最小值，该值符合以下条件：比左边的值都小，比右边相邻的值也小。最小值找到了再往右遍历找相应的最大值，依次循环。

代码如下：
```python
class Solution(object):
    # 本题采用双指针法，从左至右依次遍历
    # 本题其实和接雨水题目很类似
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # 定义获取的最大利润
        max_profit = 0
        if len(prices) <= 1:
            return max_profit

        # 分别定义股票的最小价格以及最高价格
        min_price = prices[0]
        max_price = 0
        for index in range(len(prices)):
            if prices[index] <= min_price:
                min_price = prices[index]
            elif prices[index] - min_price > max_price:
                max_price = prices[index] - min_price
        return max_price

if __name__ == "__main__":
    prices = [2, 1, 4]
    max_profit = Solution().maxProfit(prices)
    print(max_profit)
```
执行效率还算不错，达到了99%

![image.png](https://pic.leetcode-cn.com/e74453a5123a841413a184885143e647d3bc54e69b8bba3f08aefd510e4ddb79-image.png)

2019/6/5 9:10 更新

昨天写完文章后，发现用贪心算法更简化。

代码如下：
```python
class Solution(object):
    # 本题采用双指针法，从左至右依次遍历
    # 本题其实和接雨水题目很类似
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # 定义获取的最大利润
        max_profit = 0
        if len(prices) <= 1:
            return max_profit

        # 分别定义股票的最小价格以及最高价格
        min_price = prices[0]
        max_price = 0
        for price in prices:
            max_price = max(max_price, price-min_price)
            min_price = min(min_price, price)
        return max_price

if __name__ == "__main__":
    prices = [2, 1, 4]
    max_profit = Solution().maxProfit(prices)
    print(max_profit)
```

不过，执行效率倒是不升反降了，在80%左右。

![image.png](https://pic.leetcode-cn.com/58e913b96c1036af2a889a9daadfed05ddbe7b8477b3366ed82bc08f9192fd93-image.png)
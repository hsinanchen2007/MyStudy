这道题算是买卖股票的最佳时机题目系列的最难一道题了，它和第122题买卖股票的最佳时机II很相像，唯一的区别就是：在第122题中，交易股票的次数是不限制的，而在此题中确实限制在两次的。正是这两次的限制，导致这道题的难度上升了。如果对第122题不太熟悉的朋友，可以先看看这篇文章。

https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-iipython-by-fei-/

这道题我尝试了好几种方法，有些方法虽然是超出时间限制了，但我觉得方法还是可以借鉴的，所以想分享出来。

方法一：简单二分法
既然限制次数是两次，那我就可以使用二分法将prices区间分为两段，分别求左右两段区间内一次股票交易获得的最大利润即可。有些读者可能会疑惑：题目限制次数为两次，那么也可能是一次，即只需要一次股票交易就能获得最大利润。但是读者可以好好想想，其实还是能分为两段的，其中一段是最大利润，另一段利润为0即可。大致如下：
![870cd97d7501f4546cb98ed5590dd81.jpg](https://pic.leetcode-cn.com/63ecfd11fcc265425e7fc977649b09494e9a7241a2a1edebb24367ab5ffb7b3d-870cd97d7501f4546cb98ed5590dd81.jpg)

而只求一段区间内一次交易获得的最大利润正是第121题干的事儿，对第121题不太熟悉的朋友可以看看我写的这篇文章：

https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-python-by-fei-be/

既然之前就写好了方法，那这道题就好办了，只需要一次遍历，不停的划分左右区间就可以求解每次遍历得到的最大值，最后取所有值的最大值即可。
代码如下：
```Python
class Solution(object):
    # 本题可采用二分法计算
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        candidate = []
        # 记录出售股票所获得的最大收益
        max_profit = 0
        if len(prices) <= 1:
            return max_profit
        for index in range(len(prices)):
            left = self.single_profit(prices[:index])
            right = self.single_profit(prices[index:])
            max_profit = max(max_profit, left+right)
        return max_profit
            

    # 获取一段区间内完成一笔交易的最大利润
    def single_profit(self, prices):
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
    prices = [3,3,5,0,0,3,1,4]
    max_profit = Solution().maxProfit(prices)
    print(max_profit)
```

思路特别清新，但是跑起来就是超出时间限制，让我特别头疼。

方法二：进阶版二分法
其实也不算是严格的二分法，就是分两次遍历。第一次遍历是从头至尾遍历，记录每个区间内一次股票交易获得最大利润，并保存至一个数组内，方便第二轮遍历取值，这就有点像动态规划内的思想了，此处就是可以节省时间了。第二次遍历就是从尾向头遍历，选出相应坐标右边区间内一次交易的最大值，左边区间交易的最大值就可以直接从第一次遍历得到的数组获取，两者相加，即可得到两次交易的最大值。
代码如下：
```Python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        min_price, total_max_profit = float('inf'), 0
        # 记录顺序区间内每个坐标对应的利润最大值
        first_profit = [0]*len(prices)
        # 从左至右比遍历，获取顺序区间内一次交易利润的最大值
        for i in range(len(prices)):
            min_price = min(min_price, prices[i])
            total_max_profit = max(total_max_profit, prices[i]-min_price)
            first_profit[i] = total_max_profit
        max_price, max_profit = float('-inf'), 0
        # 从右至左遍历，获取逆序区间内一次交易利润的最大值，两者相加得到两次利润的最大值
        for i in range(len(prices)-1, 0, -1):
            max_price = max(max_price, prices[i])
            max_profit = max(max_profit, max_price-prices[i])
            total_max_profit = max(total_max_profit, max_profit+first_profit[i-1])
        return total_max_profit


if __name__ == "__main__":
    prices = [3,3,5,0,0,3,1,4]
    max_profit = Solution().maxProfit(prices)
    print(max_profit)
```

不过执行效率也不是很高，在30%左右。
![image.png](https://pic.leetcode-cn.com/1e9023379d796c289a4c989e74a0cb083ca90a14445d68c65d5fb691ea45b11b-image.png)

方法三：动态规划法

此方法就是正儿八经的用动态规划方法求解，不过说实话，我也没太看懂，但执行效率是真的高，我还是贴出来分享给大家。我之前写的关于动态规划方法求解的文章，我分享在评论里，大家可以先看看，相信会有所收获。
代码如下：
```Python
class Solution(object):
    def maxProfit(self, prices):
        if not prices: return 0
        n = len(prices)
        dp = [[0] * n for _ in range(3)]
        for k in range(1, 3):
            pre_max = -prices[0]
            for i in range(1, n):
                pre_max = max(pre_max, dp[k - 1][i - 1] - prices[i])
                dp[k][i] = max(dp[k][i - 1], prices[i] + pre_max)
        return dp[-1][-1]


if __name__ == "__main__":
    prices = [3,3,5,0,0,3,1,4]
    max_profit = Solution().maxProfit(prices)
    print(max_profit)
```
代码很简洁，执行效率在70%左右，还是不错了。
![image.png](https://pic.leetcode-cn.com/aef15096c22878c9b41a9b8ac0e9e7914b7993539a5a4f18b7de6ad1689b756b-image.png)

大家要是有更好的方法也请积极留言啊
本题是第121题买卖股票的最佳时机的进阶版了，虽然也是简单级别，但考虑的东西一点也不少啊！对第121题买卖股票的最佳时机不熟悉的朋友，可以先看看我写的这篇文章：

https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-python-by-fei-be/

本题的话，我也采用了两种方法。第一种方法是最直接的，本题其实就是想让你找出连续几组“相对”最小值和最大值，使得整体相加收益最大。可以理解为下图：

![qq_pic_merged_1559703560158.jpg](https://pic.leetcode-cn.com/de17b99ee9cd7579f2fdf7cdee713f741ac7e15324e48f0862d6d2fb55626da9-qq_pic_merged_1559703560158.jpg)

就是要找到符合条件的几组vally和peak值。

代码如下：
```python
class Solution(object):
    # 本题关键就是要找到连续的几组最小值和最大值
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        max_profit = 0
        if len(prices) <= 1:
            return max_profit
        # 分别定义谷底值和谷峰值
        valley = peak = prices[0]
        index = 1
        while index < len(prices):
            # 遍历查找谷底值
            while index < len(prices) and prices[index] < prices[index-1]:
                index += 1
            # 获取遍历得到的谷底值
            valley = prices[index-1]
            # 遍历查找谷峰值
            while index < len(prices) and prices[index] >= prices[index-1]:
                index += 1
            # 获取遍历得到的谷峰值
            peak = prices[index-1]
            max_profit += peak - valley
        return max_profit

if __name__ == "__main__":
    prices = [7,1,5,3,6,4]
    max_profit = Solution().maxProfit(prices)
    print(max_profit)
```
执行效率还行，在70%左右！

![image.png](https://pic.leetcode-cn.com/779275b36fe41d8d54549869eed5d7bf5f76afa71cedb0c9a1fcab04c7851850-image.png)

方法二则是骚操作了，既然我们是要找几个单增子区间内的最小值和最大值，我们其实没必要非得分别遍历，才能找出其最小值和最大值，有这么个公式。

![qq_pic_merged_1559703921042.jpg](https://pic.leetcode-cn.com/49df65bdbac536a84caaa81d144371a0f58960a42a8b9b00175278bc45244e75-qq_pic_merged_1559703921042.jpg)

是不是很骚气哈哈哈哈哈哈，代码也就很简洁了。

代码如下：
```python
class Solution(object):
    # 本题还有一种更简单的方法，不需要具体求出谷底和谷峰值
    # 可以连续求解，骚操作！
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        max_profit = 0
        if len(prices) <= 1:
            return max_profit
        for index in range(1, len(prices)):
            if prices[index] > prices[index-1]:
                max_profit += prices[index] - prices[index-1]
        return max_profit

if __name__ == "__main__":
    prices = [7,1,5,3,6,4]
    max_profit = Solution().maxProfit(prices)
    print(max_profit)
```
执行效率也是杠杠的，在97%左右！

![image.png](https://pic.leetcode-cn.com/45e45e0e9c659cded812a739d8bd7728f356711ad26746d3e04b7253d5aa9884-image.png)
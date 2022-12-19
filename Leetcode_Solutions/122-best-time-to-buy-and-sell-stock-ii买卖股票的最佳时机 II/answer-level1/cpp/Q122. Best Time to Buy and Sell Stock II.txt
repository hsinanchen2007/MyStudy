#### 贪心算法
这次题目同样是给出`N`天的价格，但是不同于上一题只买入卖出一次，这次可以买入卖出多次，求最大的收益。
看完题目之后，一脸懵，这个完全不同于上一题啊，这个难度还是简单的？咦，那一定是我没找到思路，难道又是贪心？
先捋清一下思路，买入肯定是找价格低的时候买入，卖出肯定是价格高的时候卖出，那么价格一路高涨的情况下，肯定是在最高价的时候卖出；那假如中间某一天价格稍微降低了一点点，然后又涨回去了，那我是应该在前面卖出，再重新买入，还是一直持有，等后面再卖出呢？
假如有以下四天的价格，分别是`a,b,c,d`，其中`a < b, c < b, c < d`, 其余的大小无所谓，那么在什么情况下，“买入，卖出，再买入，卖出”会比“买入，持有，持有，卖出”能得到更多收益呢？也就是什么情况下会有`b - a + d - c > d - a`呢？来来来，解一下上面的不等式，得到`b>c`，也就是说当`b>c`的时候，这不正就是我们最前面的假设条件吗？反过来说，我们不断的买入卖出就能得到更大的收益，当知道价格要降低的时候，就得卖出了！
思路已经清晰明了了，编码发挥一下，咦，过了，哈哈哈！
```
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1)
			return 0;

		int nMaxProfit = 0;
		int nBuyPrice = prices[0];
		int nSellPrice = prices[0];
		for (vector<int>::size_type i = 1; i < prices.size(); ++i) {
			if (prices[i] > nSellPrice) {
				// 价格一路高涨，我昨天不应该卖出的，换成今天卖出还能再赚个差价
				nMaxProfit += (prices[i] - nSellPrice);
				// 更新卖出价格
				nSellPrice = prices[i];
			} else {
				// 价格降低了，得重新买入了
				nSellPrice = nBuyPrice = prices[i];
			}
		}

		return nMaxProfit;
	}
};

```
文末推荐LeetCode官方题解：[Best Time to Buy and Sell Stock II - LeetCode官方题解](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-ii-by-leetcode/)
顺便再推荐大牛团灭股票问题的文章：[一个方法团灭6道股票问题](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-3/)
我果真不适合写题解，写文章啊！
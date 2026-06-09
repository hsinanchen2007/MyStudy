#### 解法一：暴力出奇迹
暴力枚举第i天买入，第j天卖出的股票带来的收益，取最大值即可。
#### 解法二：贪心
对于在第i天卖出的股票，最大收益是在前面i-1天的最低价买入，该天的收益即为`prices[i]-nMinPrice`，所以计算第i天的最大收益时，只需要维护一个最低买入价格即可。总体的最大收益则取N天的最大值。
```
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 0)
			return 0;

		int nMaxProfit = 0;
		int nMinPrice = prices[0];
		for (vector<int>::size_type i = 1; i < prices.size(); ++i) {
			nMaxProfit = std::max(nMaxProfit, prices[i] - nMinPrice);
			nMinPrice = std::min(nMinPrice, prices[i]);
		}
		return nMaxProfit;
	}
};
```
文末推荐大牛团灭股票问题的文章：[一个方法团灭6道股票问题](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-3/)
我果真不适合写题解，写文章啊！
拿了个笔，画了画。
发现既然没有限制交易次数，那就两天一组的看。
只要第二天的价格比前面那天的价格便宜就可以算一次交易，
算差价，能赚钱就买，不能赚钱就跳，
然后对这样的交易收益进行累加就OK了。

```
    public int maxProfit(int[] prices) {
        int profit = 0;
        for (int i = prices.length - 1; i > 0; i--) {
			if (prices[i] > prices[i-1]) {
				profit += prices[i] - prices[i-1];
			}
		}
        return profit;
    }
```

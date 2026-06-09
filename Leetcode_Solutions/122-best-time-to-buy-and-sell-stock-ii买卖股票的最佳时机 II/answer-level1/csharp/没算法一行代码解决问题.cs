不限制交易次数所以肯定是每天买了第二天卖，去掉所有负收益的交易后，就是最大收益。SO，一行代码解决问题。

```
    public int MaxProfit(int[] prices)
    {
            return prices == null || prices.Length == 0
                ? 0
                : prices.Skip(1).Zip(prices, (p0, p1) => p0 - p1).Where(t => t > 0).Sum();
    }

```

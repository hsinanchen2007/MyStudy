我是真的不适合买股票。
写完了，我想着这题肯定要考虑数组长度，然后我就写了个 if(length == 1) return prices[0]; QAQ
接下来说题解：
1. 贪心的思路：
一句话来讲：只要当前我能赚钱，我就计算我能赚多少，然后和之前计算的赚钱数比较
先以 buy = prices[0] 为我们股票的买入点，之后开始遍历 prices 数组
如果 prices[i] 比我们的 buy 要小，我们肯定是要以 prices[i] 作为买入点的。 因为如果以后股票价格涨得没有 buy 高，那么肯定是亏的，如果涨得比 buy 高，那么你 prices[i] 买入，到时候再卖出赚的更多。
如果 prices[i] 比我们的 buy 要大，那我们就计算 have = prices[i] - buy, 看看能赚多少，并且和之前计算的赚钱数比较，保留较大值，这样最后保留下来的就是赚的最多的钱。(have 初始值为 0， 因为一开始没有买股票，没有赚也没有亏)

C#代码：
```
        public int MaxProfit(int[] prices)
        {
            if (prices.Length < 2) return 0;
            // 当前买入时的价格
            int buy = prices[0];
            // 当前赚的钱
            int have = 0;
            // 赚到过最多的钱
            int max = prices[1] - prices[0];

            for (int i = 1; i < prices.Length; i++)
            {
                // 如果当前价格比我买入时便宜，我就重新买(以当前价格为买入点)
                if (buy > prices[i]) buy = prices[i];
                // 如果当前价格比我买入时贵，我就计算这个时候我卖出去能赚多少
                else have = prices[i] - buy;
                // 看看有没有比我之前赚的多
                max = Math.Max(max, have);
            }
            return max;
        }
```

2. 动态规划：
动态规划的思考过程就是一个从上往下再从下往上的过程。
从上往下：
我们假设 第 i 天，卖出，赚的钱最多。 那么赚的是多少呢？
我们看第 i - 1 天卖出时，如果第 i 天卖出，赚的钱是个负数，也就是亏了， 那么我们第 i 天卖出赚的钱就是 第 i 天股票价格 减去 第 i-1 天股票的价格（即，第 i - 1 天买入， 第 i 天卖出）。
而如果第 i-1 天卖出赚钱了呢？那就开始递归呗。
于是得到递归式：
![image.png](https://pic.leetcode-cn.com/8a94e710fb6b9d340aeeee0f8d1ff1d91762abb14bc4b6b1011f2fd3f49e3bdf-image.png)

C#代码：
```
        public int MaxProfit(int[] prices)
        {
            if (prices.Length < 2) return 0;
            int m = 0;
            int max = 0;
            for(int i = 1; i < prices.Length; i++)
            {
                m = Math.Max(m, 0) + prices[i] - prices[i - 1];
                max = Math.Max(max, m);
            }
            return max;
        }
```

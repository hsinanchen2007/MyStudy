这是一个最大连续子数组和的问题。有同学会问，这是怎么看出来的，因为在数组中求两点的差，而两点之差可以转换成求和问题。也许你还是一脸懵，这怎么想的到。如果你学过高等数学，对牛顿莱布尼茨公式有印象的话：

$$
\int_{a}^{b}f(x){\mathrm{d}}x=F(x)\bigg|_{a}^{b}=F(b) - F(a)
$$

只不过，在我这里，F() 函数不是连续的，而是离散化的，$a$ 和 $b$ 表示数组的下标。但是这不影响我们得出正确的结论。

总结下：**区间和可以转换成求差的问题，求差问题，也可以转换成区间和的问题**。

在上面的公式中，我们把 $F()$ 表示的数组称为前缀和。

最大连续子数组和可以使用动态规划求解， $dp[i]$ 表示以 $i$ 为结尾的最大连续子数组和，递推公式为：

$$
dp[i] = max(0, dp[i-1])
$$

那么先来看我们的版本一：

**版本一**

```C++ []
int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;
    vector<int> diff(prices.size() - 1);
    for (int i = 0; i < prices.size() - 1; ++i) {
        diff[i] = prices[i+1] - prices[i];
    }
    
    vector<int> dp(diff.size());
    dp[0] = max(0, diff[0]);
    int profit = dp[0];
    for (int i = 1; i < diff.size(); ++i) {
        dp[i] = max(0, dp[i-1] + diff[i]);
        profit = max(profit, dp[i]);
    }
    return profit;
}
```

**版本二**

进一步我们发现，dp 数组是可以被优化掉的。

```C++ []
int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;
    vector<int> diff(prices.size() - 1);
    for (int i = 0; i < prices.size() - 1; ++i) {
        diff[i] = prices[i+1] - prices[i];
    }
    
    int last = 0;
    int profit = last;
    for (int i = 0; i < diff.size(); ++i) {
        last = max(0, last + diff[i]);
        profit = max(profit, last);
    }
    return profit;
}
```

**版本三**

仔细观察，你会发现，diff 数组也可以被优化掉。

```C++ []
int maxProfit(vector<int>& prices) {
    int last = 0, profit = 0;
    for (int i = 0; i < (int)prices.size() - 1; ++i) {
        last = max(0, last + prices[i+1] - prices[i]);
        profit = max(profit, last);
    }
    return profit;
}
```


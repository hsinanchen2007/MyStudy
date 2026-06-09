**思路**：从第一天到最后一天，不错过每一次隔天的上涨。
```
public int MaxProfit(int[] prices)
{
    int result = 0;

    for (int i = 1; i < prices.Length; i++)
        {
        var temp = prices[i] - prices[i - 1];
        if (temp > 0)
        {
            result = result + temp;
        }
    }

    return result;
}
```

思路就是把所有两两价格差都存在一个表里，当然第一次运行超时了，后来剔除了一些显然不合理的（跨度更大但价差更小的组合）。
然后就是循环挑两个价格差相加找最大的（剔除时间跨度重叠的），时间和空间复杂度都是打败不到10%的水平。。。代码如下：
public int MaxProfit(int[] prices)
{
    int result = new int();
    List<int[]> profits = new List<int[]>();
    for (int i = prices.Length - 1; i > 0; i--)
    {
        int max = 0;
        for (int j = i - 1; j > -1; j--)
        {
            if (prices[i] - prices[j] > max)
            {
                max = prices[i] - prices[j];
                int[] maxProfit = new int[] { j, i, prices[i] - prices[j] };
                profits.Add(maxProfit);
            }
        }
    }
    if (profits.Count > 1)
    {
        foreach (var item in profits)
        {
            foreach (var item2 in profits)
            {
                if (item == item2)
                    continue;
                if (item[1] > item2[0])
                    continue;
                if ((item[2] + item2[2]) > result)
                    result = item[2] + item2[2];
            }
            if (item[2] > result)
                result = item[2];
        }
    }
    else if (profits.Count == 1)
    {
        result = profits[0][2];
    }
    return result;
}
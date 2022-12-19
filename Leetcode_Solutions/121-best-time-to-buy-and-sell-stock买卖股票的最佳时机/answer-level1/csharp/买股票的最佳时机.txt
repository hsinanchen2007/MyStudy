**思路1：** 暴力解法
```
public int MaxProfit(int[] prices)
        {
            int result = 0;
            int minStart = int.MaxValue;

            for (int i = 0; i < prices.Length; i++)
            {
                //优化：如果起始值比之前的起始值要大就没必要算了
                if (prices[i] < minStart)
                {
                    for (int j = i + 1; j < prices.Length; j++)
                    {
                        int currentProfit = prices[j] - prices[i];
                        if (currentProfit > result)
                        {
                            result = currentProfit;
                        }
                    }
                    if (prices[i] < minStart)
                    {
                        minStart = prices[i];
                    }
                }
            }

            return result;
        }
```
**思路二：** 一次遍历，暴力解法的问题在于计算了很多无用的插值，比如[7,1,5,3,6,4]，如果知道了1比7小，其实就没必要计算1-7，5-1...了。首先设置最小股票点，然后遍历过程中如果比最小点小则置换，如果比他大则计算差值并更新结果。
```
public int MaxProfit2(int[] prices)
        {
            int result = 0;
            int lowPoint = int.MaxValue;

            for (int i = 0; i < prices.Length; i++)
            {
                if (prices[i] < lowPoint)
                {
                    lowPoint = prices[i];
                }
                else {
                    result = Math.Max(result, prices[i] - lowPoint);
                }
            }

            return result;
        }
```

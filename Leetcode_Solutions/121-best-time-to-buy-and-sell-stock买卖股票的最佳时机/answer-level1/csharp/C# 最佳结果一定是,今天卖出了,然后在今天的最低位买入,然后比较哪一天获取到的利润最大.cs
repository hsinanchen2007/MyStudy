### 解题思路

##### 1. 题目概述：买卖股票的最佳时机

##### 2. 思路：
   - 特征：股票每日的价格构成了一个折线图;若想获得最大的利润,那么就应该是很低的价格买入,然后在以后以很高的价格卖出;
   - 方案：站在结果的角度来看,有一天卖出了,那么一定是当天之前最低价格入手的,然后以当天价格卖出的;截止当天最低价格是可知的,当天价格也是明确的;
   - 结果：只要找到每天卖出的最大利润,就得到了解

##### 3. 知识点：数组 DP

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(1)


### 代码

```csharp []
public class Solution {
        public int MaxProfit(int[] prices)
        {
            var forReturn = 0;
            if (prices.Length == 0) return forReturn;

            var minValue = prices.First();
            foreach (var priceItem in prices)
            {
                minValue = Math.Min(priceItem, minValue);

                if (priceItem > minValue && priceItem - minValue > forReturn)
                    forReturn = priceItem - minValue;
            }

            return forReturn;
        }
}
```
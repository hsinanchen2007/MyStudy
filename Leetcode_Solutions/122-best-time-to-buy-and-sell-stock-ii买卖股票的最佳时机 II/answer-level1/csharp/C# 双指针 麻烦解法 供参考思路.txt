我是用双指针的思想做的,比最优解麻烦很多,想复杂了.
不过也是时间复杂度O(N),空间复杂度O(3)
也不算太麻烦吧,供大家参考思路
```
public class Solution {
    public int MaxProfit(int[] prices) {
        if (prices == null)
        {
            return -1;
        }
        if (prices.Length < 2)
        {
            return 0;
        }
        int result = 0;//利润结果
        int point1 = 0;//上一个购买节点 默认为0
        int point2 = 1;//当前节点
        while (point2 < prices.Length - 1)
        {
            //当前价格在上涨 
            if (prices[point2] > prices[point2 - 1])
            {
                //不会继续上涨 
                if (prices[point2 + 1] <= prices[point2])
                {
                    //卖出
                    result += prices[point2] > prices[point1] ? prices[point2] - prices[point1] : 0;
                    point1 = point2;
                }
            }
            //当前价格在下跌 
            if (prices[point2] < prices[point2 - 1])
            {
                //不会继续下跌
                if (prices[point2 + 1] >= prices[point2])
                {
                    //买入
                    point1 = point2;
                }
            }
            point2++;
        }
        //最后一个节点
        result += prices[point2] > prices[point1] ? prices[point2] - prices[point1] : 0;
        return result;
    }
}
```
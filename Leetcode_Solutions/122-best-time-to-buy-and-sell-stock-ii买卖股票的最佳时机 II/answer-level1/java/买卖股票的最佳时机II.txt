### 解题思路
因为可以买卖多次，所以只要有赚都可以考虑卖出去，而如果后面在赚的过程中发现下一个会亏，则此次买卖结束，下一个亏点为可能买入点，为什么是可能买入点，因为要考虑后面一直都是亏的情况就不需要买入了；

#### 示例

1. 7,1,5,3,6,4    在交易经过5和3的时候发现会亏，立马卖出赚取5-1，先买入3，在经过6和4的时候发现会亏立马卖出赚取6-3，结果为6-3+5-1
2. 7,1,5,4,3,2    在交易经过5和4的时候发现会亏，立马卖出赚取5-1，先买入3，一直到最后2的时候发现还比买入点少，则不统计这笔买卖，结果为5-1

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int result = 0;
        int minPrice = Integer.MAX_VALUE;

        for (int index = 0; index < prices.length; index++) {
            int current = prices[index];
            if (minPrice < current) {
                result += current - minPrice;
            }
            minPrice = current;
            continue;
        }

        return result;
    }
}
```
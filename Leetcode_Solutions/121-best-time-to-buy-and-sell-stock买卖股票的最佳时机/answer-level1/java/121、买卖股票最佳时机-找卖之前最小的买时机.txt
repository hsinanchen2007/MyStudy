### 解题思路
菜鸟如我，总结不出这个写法的思想

总之，满足条件 卖出(sell) 在 买入(buy) 之后，即在index上，有 buy < sell ,而 sell 又满足 ： sell < prices.length

之后一路比较，buy 只要守住 sell 之前元素的最小值即可，sell 往前冲

当 prices[sell] < prices[buy] 的时候，即此时找到一个更小的buy 时机，则将 buy = sell ,而 sell 继续向前

当 prices[sell] > prices[buy] 的时候，意味着它有可能是最大值，将这个差值与之前缓存的 max 相比较，取较大者

如此循环，最终max就是答案

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices == null){
            return 0;
        }

        int arrLen = prices.length;
        if(arrLen == 0 || arrLen == 1){
            return 0;
        }

        int buy = 0;
        int sell = 1;
        int max = 0;

        while(buy < sell && sell < arrLen){
            int diff = prices[sell] - prices[buy];
            if(diff < 0){
                //buy每次指向sell前面最小的值
                buy = sell;
                sell ++;
            }else{
                max = max >= diff ? max : diff;
                sell ++;
            }
        }
        return max;
    }
}
```
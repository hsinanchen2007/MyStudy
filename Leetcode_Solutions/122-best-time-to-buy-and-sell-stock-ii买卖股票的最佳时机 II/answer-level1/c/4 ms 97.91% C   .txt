### 解题思路
其实这题给人的感觉，挺像割韭菜的。
审题：（你必须在再次购买前出售掉之前的股票）
可以看到题目仅仅限制操作顺序而并没有限制单日的交易次数，也就是可以在当天卖出后再买入，因为处于上帝视角，所以可以预知后一天的涨跌。
并且题中并不涉及交易费用，那我们可以采取超短线赚了就跑型交易手法：第i+1天的价格比i天高，我们就卖出一次，割一次韭菜，交易完成后我们开始准备下一波行动。一次遍历完成，我们就能割完所有的韭菜，最佳结果就出来了。

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    int shouyi = 0;
    int i = 0;
    for(;i < pricesSize-1;i++){
        if(prices[i] < prices[i+1])
            shouyi = shouyi + prices[i+1] - prices[i];
    }
    return shouyi;
}


```
### 思路
![image.png](https://pic.leetcode-cn.com/ededf626b2eecedeca48614d11797dff518347e7f87c13a6331c89a939da33ac-image.png)

### 解题思路
1、本题的思路非常简单，就是在转折的位置买入以及在下个转折前一个位置卖出，因此，主要是寻找转折位置
2、转折位置实际非常好找，就是上一个位置比当前位置大，这样就是转折位置，因此比较当前值<上个值，此时计算

### 代码

```c
int maxProfit(int *prices, int pricesSize)
{
    int buy;
    int sell;

    if (pricesSize <= 1) {
        return 0;
    }

    buy = prices[0]; //初始买入
    int profit;
    int index;
    profit = 0;
    for (index = 1; index < pricesSize; index++) {
        if (prices[index] < prices[index - 1]) { //转折位置
            /* code */
            sell = prices[index - 1];
            profit += (sell - buy);
            buy = prices[index];
        }
    }

    sell = prices[index - 1];
    if (sell > buy) { //最后一次可能没有转折位置了，如果可以交易就直接交易
        profit += (sell - buy);
    }

    return profit;
}
```
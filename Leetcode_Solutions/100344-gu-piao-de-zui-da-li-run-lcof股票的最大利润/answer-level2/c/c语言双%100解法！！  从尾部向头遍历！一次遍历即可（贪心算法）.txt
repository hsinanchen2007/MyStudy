### 解题思路
（1）维护三个变量，一个是max，一个是profit，一个是ans：

        max 指的是从数组尾部到当前位置的所有价钱中最大的那一个价格；
        profit 指的是如果从当前位置价格买入，到max价格时卖出能得到的利润 profit = max-prices[当前位置]
        ans 指的是所有遍历的profit中最高的那个

（2）从数组尾部向头部遍历：

    每次遍历计算一次profit，会得到以下几种情况；
        1.profit<0,说明当前位置的价格更高,那么更新一下max
        2.profit>0 那么拿他和ans比较，如果大于ans，那么profit的值就替换ans的值

    最后返回ans

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    int ans = 0;

    if(pricesSize>=2){                          //交易日不满两天直接返回0
        int max = prices[pricesSize-1],         //将max初始化为最后一天的值
        int profit;
        for(int i = pricesSize-2;i>=0;i--){     //从最后一天开始向第一天遍历
            profit = max-prices[i];              //计算当前的profit
            if(profit<=0)
                max = prices[i];
            else if(profit>ans)
                ans = profit;
        }
    }

    return ans;
}
```
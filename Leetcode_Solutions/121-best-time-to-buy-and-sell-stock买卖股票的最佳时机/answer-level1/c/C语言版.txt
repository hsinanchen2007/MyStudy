动态规划问题，第i天的最大收益有两种情况：
一种是前i-1天中的最大收益，与第i天无关
另一种是第i天的价格减去前i-1天中的最小值min，故：
第i天的最大收益为：MAX（前i-1天中的最大收益，第i天的价格-min）。
不过竟然还有空数组这种情况，不愧是力扣。。。
代码如下：

#define MAX(a,b) a>b ?a:b

int maxProfit(int* prices, int pricesSize){
    if(pricesSize == 0) return 0;

    int max_profit = 0;
    int min,i;//min用于记录前i-1天的最小值
    min = prices[0];
    for(i = 1;i < pricesSize;i++){
        max_profit = MAX(max_profit,prices[i] - min);
        if(prices[i] < min){
            min = prices[i];
        }
    }
    return max_profit;
}
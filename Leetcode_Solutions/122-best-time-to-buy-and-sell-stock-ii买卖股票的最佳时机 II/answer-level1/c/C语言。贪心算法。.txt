/**
 * 贪心算法。如果把股票价格画成曲线图，相当于我们每次都在曲线底部买入，顶部卖出。
 * j表示当前价格，如果当前价格小于前一天价格，说明股票正在跌，那么在j-1的时候就该卖掉，且更新i为j
 * 如果当前价格大于前一天价格，说明股票正在涨，j指向下一天，i不变。
 */
```
int maxProfit(int* prices, int pricesSize){
	int sum = 0;
	int i, j;
	for(i = 0, j = 1; j <= pricesSize; j++){
	    if(j == pricesSize || prices[j] < prices[j-1]){
		    sum += prices[j-1] - prices[i];
		    i = j;
	    }
    }
    return sum;
}
```

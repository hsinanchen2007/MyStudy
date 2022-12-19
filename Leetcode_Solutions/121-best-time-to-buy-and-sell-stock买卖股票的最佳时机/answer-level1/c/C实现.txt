### 解题思路
更新最低价格和最大利润

### 代码

```c
int maxProfit(int *prices, int pricesSize) {
	int minPrice;
	int maxProfit = 0;    
    if ((pricesSize <= 0) || (prices == NULL)) {        
        return 0;
    }    
    minPrice  = prices[0];
	for (int i = 0; i < pricesSize; i++) {	
		if ( prices[i] < minPrice) {
			minPrice = prices[i];
		} else if ((prices[i] - minPrice) > maxProfit) {
		    maxProfit = prices[i] - minPrice;
		}
	}    
	return maxProfit;
}
```
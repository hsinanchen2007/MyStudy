```cpp
/**
 * j指向当前遍历的值，i指向当前遍历过的值中的最小值，max表示当前的最大利润。
 * 当prices[j] < prices[i]，更新i，否则判断prices[j] - prices[i]是否大于max，然后更新max
 */

int maxProfit(int* prices, int pricesSize){
    int max = 0;
    for(int i = 0, j = 0; j < pricesSize; j++){		
        if(prices[j] < prices[i]){
            i = j;
	}else if(prices[j] - prices[i] > max){
            max = prices[j] - prices[i];
        }
    ｝
    return max;
}

```

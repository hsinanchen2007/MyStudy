```
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) > (y) ? (y) : (x))
// dp
int maxProfit(int* prices, int pricesSize){
    if (pricesSize <= 1) {
        return 0;
    }

    //int* dp = (int*)malloc(sizeof(int) * pricesSize);

    //dp[0] = prices[0];
    //dp[1] = prices[0] > prices[1] ? 0 : prices[1] - prices[0];
    int max = 0;
    int min = prices[0];
    for (int i = 1; i < pricesSize; i++) {
        min = MIN(prices[i], min); 
        max = MAX(prices[i] - min, max);  
    }
    return max;
}
```

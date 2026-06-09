```
#define Max(i,j) i>j?i:j
int Profit(int* prices, int pricesSize){
    if(pricesSize < 1) return 0;
    int dp_i_0 = 0, dp_i_1 = -prices[0] ;
    for(int i = 0; i < pricesSize; i++)
    {
        dp_i_1 = Max(dp_i_1, dp_i_0 - prices[i]);
        dp_i_0 = Max(dp_i_0, dp_i_1 + prices[i]);
    }
    return dp_i_0;
}
int maxProfit(int k, int* prices, int pricesSize){
    if(pricesSize < 1) return 0;
    if(k > pricesSize / 2 ) return Profit(prices,pricesSize);
    int dp_0[k + 1],dp_1[k + 1];
    memset(dp_1,0,sizeof(dp_1));
    memset(dp_0,0,sizeof(dp_0));
    for(int i = 0; i < pricesSize; i++)
        for(int j = k; j >= 1; j--)
        {
            if( i == 0)
            {
                dp_0[j] = 0;
                dp_1[j] = -prices[i];
                continue;
            }
            dp_0[j] = Max(dp_0[j] , dp_1[j] + prices[i]);
            dp_1[j] = Max(dp_1[j] , dp_0[j - 1] - prices[i]);
        }
    return dp_0[k];
}
```

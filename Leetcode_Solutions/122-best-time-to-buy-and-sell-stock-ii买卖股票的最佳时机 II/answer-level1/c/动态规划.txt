int maxProfit(int* prices, int pricesSize){
    int ret = 0, * dp, i, j, k, temp1, temp2;

    if((prices == NULL) || (pricesSize == 0))
    {
        return 0;
    }

    dp = (int* )malloc(pricesSize * sizeof(int));

    for(i = 0; i < pricesSize; i++)
    {
        dp[i] = 0;

        for(j = i - 1; j >= 0; j--)
        {
            if(prices[i] > prices[j])
            {
                temp1 = dp[j];

                for(k = j - 1; k >= 0; k--)
                {
                    temp1 = dp[k] > temp1 ? dp[k] : temp1;
                }

                temp2 = prices[i] - prices[j] + temp1;

                dp[i] = temp2 > dp[i] ? temp2 : dp[i];
            }
        }

        ret = dp[i] > ret ? dp[i] : ret;
    }

    free(dp);

    return ret;
}
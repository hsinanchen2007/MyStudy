int maxProfit(int* prices, int pricesSize){
    int ret = 0, i, j, temp;
    int* each_max = (int* )malloc(pricesSize * sizeof(int)); 

    for(i = 0; i < pricesSize; i++)
    {
        each_max[i] = 0;

        for(j = i; j >= 0; j--)
        {
            if(prices[i] > prices[j])
            {
                temp = prices[i] - prices[j] + each_max[j];
                each_max[i] = temp > each_max[i] ? temp : each_max[i];
            }
        }

        ret = each_max[i] > ret ? each_max[i] : ret; 
    }

    free(each_max);

    return ret;
}
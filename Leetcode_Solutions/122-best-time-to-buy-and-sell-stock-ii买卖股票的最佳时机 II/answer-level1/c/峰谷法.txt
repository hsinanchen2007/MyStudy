int maxProfit(int* prices, int pricesSize){
    if(prices == NULL || pricesSize < 2) return 0;

    int i,j;
    int low=0,high=0,sum = 0,min=0;
    int *src = (int *)malloc(sizeof(int) * (pricesSize + 2));

    src[0] = prices[0];
    src[pricesSize + 1] = prices[pricesSize-1];
    for(i = 0;i< pricesSize;i++){
        src[i+1] = prices[i];
    }

    for(i = 1;i <= pricesSize;i++){
        //低点买入
        if(src[i] <= src[i-1] && src[i] < src[i+1]){
            low = i;
        }
        //高点卖出
        if(src[i] > src[i-1] && src[i] >= src[i+1]){
            high = i;
            sum = sum + src[high] - src[low];
        }
    }

    return sum;
}
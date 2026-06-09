int maxProfit(int* prices, int pricesSize){  
    if(prices == NULL || pricesSize < 2) return 0;
    int left = 0,right = 0,min = 0;
    int sum = 0;
    int i,j;

    int *f = (int *)malloc(sizeof(int) * (pricesSize + 1));
    for(i = 0;i<= pricesSize;i++){
        f[i] = 0;
    }

    if(prices[0] < prices[1]){
        left = 0;
        min = 0;
    }else{
        left = 1;
        min = 1;     
    }
    right = 1;

    for(i = 2;i<pricesSize;i++){
        if(prices[i] < prices[min]){
            //移动min
            min = i;
        }

        if(prices[i] >= prices[right]){
            right = i;
            for(j = left + 1;j< i ;j++){
                if(prices[j] < prices[left]){
                    left = j;
                }
            }
        }

        if((prices[i] - prices[min]) > (prices[right] - prices[left])){
            left = min;
            right = i;
        }

  
    }

    sum = prices[right] - prices[left];
    return sum;
}
```
int maxProfit(int* prices, int pricesSize){
	int sum = 0;
	int i, j;
	for(i = 0, j = 0; j < pricesSize ; j++){
	    if(j == pricesSize-1 ||prices[j+1] < prices[j]){
		    sum += prices[j] - prices[i];
		    i = j + 1;
	    }
    }
    return sum;
}
```
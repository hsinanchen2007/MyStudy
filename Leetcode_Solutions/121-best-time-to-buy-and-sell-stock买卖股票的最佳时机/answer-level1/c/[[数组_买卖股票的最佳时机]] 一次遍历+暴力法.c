
一次遍历：理想折线图。在每天考虑两件事：今天的价格是最低吗？今天卖掉目前史低股票能赚多少？

```c
int maxProfit(int* prices, int pricesSize){
    if(prices==NULL||pricesSize==0) return 0;
    int minprice=prices[0],pro=0;
	for(int i=1;i<pricesSize;i++){
		prices[i]-minprice>pro ? pro=prices[i]-minprice:(NULL);
		prices[i]<minprice ? minprice=prices[i]:(NULL);
	} 
	return pro;	
} 
```

暴力法：从后往前遍历，对于每个i天，都遍历一次0~i-1天卖出股票能赚多少
```c
int maxProfit(int* prices, int pricesSize){
	int pro=0;
	for(int i=pricesSize-1;i>0;i--){
		for(int j=i-1;j>=0;j--){
			if(prices[i]-prices[j]>pro){
				pro=prices[i]-prices[j];
			}
		}
	}
	return pro;
}
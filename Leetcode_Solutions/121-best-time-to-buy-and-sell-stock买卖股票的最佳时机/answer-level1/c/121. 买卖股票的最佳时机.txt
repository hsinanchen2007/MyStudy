# 121. 买卖股票的最佳时机
- 思路:
最大的利润即为数组中两数的最大差值。
一次遍历实现最大差值的获取，需要两个变量：
```
	min_head    //表示当前寻找的数组范围内最小的数。
	max_diff    //表示当前最大的差值。
```
	
- 不论遍历到哪一步，如果此时的值小于之前的min_head，那么我们就保存这个值，后面的较大值一和他的差值更大。
- 如果此时的值大于之前的min_head，判断当前差值是否大于max_diff。
- 这样通过一次遍历就可以获得最大的差值。
```
int maxProfit(int* prices, int pricesSize){
	if( prices == NULL || pricesSize <= 0 ){
		return 0;
	}
	int i;
	int min_head = prices[0];
	int max_diff = 0;
	for(i = 1; i < pricesSize;++i){
		if( prices[i] <= min_head ){
			min_head = prices[i];
		}else{
			if( max_diff < (prices[i]-min_head) ){
				max_diff = prices[i]-min_head;
			}
		}
	}
	return max_diff;
}
```

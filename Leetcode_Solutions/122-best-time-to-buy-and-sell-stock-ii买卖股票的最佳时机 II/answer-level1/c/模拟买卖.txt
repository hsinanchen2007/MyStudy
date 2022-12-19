### 解题思路
设置一个预购买和预售出：pre_buy、pre_slae，和真实购买和售出：buy，sale。
算法核心就是预计当天买第二天卖，如果有得赚就执行，然后再卖出的同时再预计买进，没得赚就预计第二天买第三天卖，如此往复。

假定第一天预购买，然后从第二天开始进入循环，如果第二天价格比第一天高，那么确认购买并且在第二天卖出，同时在第二天再次预购买，第三天预售出；如果第二天价格比第一天低，那么预购买换成第二天，第三天预卖出。
### 代码

```c
int maxProfit(int* prices, int pricesSize) {
	int buy = -1, sale = -1, pre_buy = 0, pre_sale = 1;
	int time = 1, profit = 0;
	while (time < pricesSize) {
		if (prices[pre_sale] > prices[pre_buy]) {
			sale = pre_sale;
			buy = pre_buy;
			pre_buy = time;
			pre_sale = pre_buy + 1;
			profit += prices[sale] - prices[buy];
		}
		else {
			pre_buy = time;
			pre_sale = pre_buy + 1;
		}
		time++;
	}
	return profit;
}
```
![2.png](https://pic.leetcode-cn.com/ce6257a06f347d2a5f542aec58b577d8f4f5859cd151c1d0bb1322dae344d3ac-2.png)

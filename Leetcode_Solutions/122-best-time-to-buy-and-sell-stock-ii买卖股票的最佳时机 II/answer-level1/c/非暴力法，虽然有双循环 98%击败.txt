### 解题思路
![图片.png](https://pic.leetcode-cn.com/f169bf80046a77a7cc9c67d92d46b3547db66bdd2f70c3e1924693379ea8b573-%E5%9B%BE%E7%89%87.png)

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    int maxprofit=0;int lastday=0;int sub=0;int i=0;
	while(i<pricesSize){
		int j=i+1,lastday=i;
		while(j<pricesSize){
			if(prices[i]<prices[j]&&prices[j]>prices[lastday]){
				lastday=j;
			}else{
				if(prices[lastday]-prices[i]<=0){
					sub=0;
				}else{
					sub=prices[lastday]-prices[i];
				}
				maxprofit+=sub;
				break;
			}
		}
		i=j;
	}
	return maxprofit;
}
```
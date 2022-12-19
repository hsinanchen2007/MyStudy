### 解题思路
此处撰写解题思路
循环：以每日的价格作为买入价，查看此日之后的最高价，作差即是这日买入，再卖出得到的最大利润；
亮点：由后往前遍历（prices[len-2]至prices[0]），这样得到最高价时，只需要定义一个变量用于保存当前最高价，每次循环时，更新最高价只需另新值与当前最高价进行比较即可。
具体可见代码注释
时间，99.59%
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
		int len = prices.length;
		if (len < 2) return 0;
		int profit = 0;
		int temMax = 0;
		for (int i=len-2; i>=0; i--) {
			int temProfit = 0; // 本次循环的最大利润
			int tem = prices[i]; // 买入价
			int temNum = prices[i+1];
			temMax = temNum>temMax ? temNum : temMax;
			temProfit = temMax>tem ? temMax - tem : 0;
			profit = temProfit>profit ? temProfit : profit;
		}
		return profit;
    }
}
```
### 解题思路
这道题是求连续子数组的最大和的一种变式，我们希望将价格按照时间先后顺序存储的数组先进行转化，转化为每个元素都用来表示当前时间比前一个时间价格涨跌多少的数组，至于数组的转化可以在原数组的基础上进行，不需要额外开辟空间。这样一来，我们用动态规划算法就能算出买卖该股票一次可能获得的最大利润是多少。

具体实现看下面代码注释分析：

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        //当数组长度为0或1时，返回0并结束函数
		if(prices.length == 0 || prices.length == 1) return 0;
		//在原数组的基础上从后往前计算相邻元素的差值覆盖到原数组上，表示在一个时间
		//点到下一个时间点的涨跌情况，这样一来，price[0]这个元素就用不到了
		for(int i = prices.length-1;i>0;i--) {
			prices[i] = prices[i] - prices[i-1];
		}
		int partArray = prices[1];//记录子数组串的值
		int max = prices[1];//记录所有子数组串中和最大的和的值
		for(int j = 2; j<prices.length;j++) {
			if(partArray>0) {
				partArray = partArray + prices[j];
			}else {
				partArray = prices[j];
			}
			//每次循环都要比较出目前所有子数组串中和最大的和的值，有则替换
			if(partArray >max)
				max = partArray;
		}
		return max >= 0 ? max : 0;
    }
}
```
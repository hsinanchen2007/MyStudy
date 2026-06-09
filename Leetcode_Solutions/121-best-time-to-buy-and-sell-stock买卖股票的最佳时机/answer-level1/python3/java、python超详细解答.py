## 解题分析
我觉得，这道题拿到之后就应该有第一反应，这道题的关键就是怎么一次遍历，找到答案；
关键就是在左边找到一个最小值，然后右边找到一个最大值，这样相减即是最大利润；

所以我们定义一个min变量来定义所遍历到的最小值，再定义一个变量maxValue来定义目前的最大利润，因为没有利润就返回0，所以这个变量的初始值要为0，然后我们遍历每次拿 当前变量减去之前的最小值再和之前的最大值maxValue选出最大的赋值给maxValue，再拿当前元素和min比，把最小值赋值给min；这样遍历一轮之后就可以得到结果；时间复杂度为O(n);


## 代码
ps：这里笔者使用的jdk为1.8、python3.7

- java实现

	```java
	class Solution {
	    public int maxProfit(int[] prices) {
	        int maxValue = 0;
	        if (Objects.isNull(prices) || prices.length == 0) {
	            return maxValue;
	        }
	        int min = prices[0];
	        for (int i = 1; i < prices.length; i++) {
	            maxValue = Math.max(maxValue, prices[i] - min);
	            min = Math.min(min, prices[i]);
	        }
	        return maxValue;
	    }
	}
	```

- python实现

	```python
	class Solution:
	    def maxProfit(self, prices: List[int]) -> int:
	        if prices is None or len(prices) == 0:
	            return 0
	        max_value = 0
	        min_ele = prices[0]
	        for i in range(1, len(prices)):
	            temp = prices[i]
	            max_value = max(max_value, temp - min_ele)
	            min_ele = min(min_ele, temp)
	        return max_value
	```

更多易懂教程可以关注知乎[@司南牧](https://www.zhihu.com/people/yuanmuou/activities)
这道题其实是一个非常简单的将多个线段重叠然后算最终线段的长度问题。
```
int maxProfit(vector<int>& prices) {
	int totalProfite = 0;
	for (size_t i = 1; i < prices.size(); i++)
	{
		if (prices[i - 1] < prices[i])
			totalProfite += (prices[i]-prices[i-1]);
	}
	return totalProfite;
}
```
![image.png](https://pic.leetcode-cn.com/22494008a1bba36c0d8bde7da6be1eea9114ea75320f995a94a2eb1916034ce4-image.png)

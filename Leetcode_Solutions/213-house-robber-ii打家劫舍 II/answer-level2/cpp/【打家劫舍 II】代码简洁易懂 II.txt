### 前情提要：  
[【打家劫舍】 代码简洁易懂](https://leetcode-cn.com/problems/house-robber/solution/da-jia-jie-she-by-ikaruga/)  
因为这个解题是对 打家劫舍 的思路进行升级，所以请先花一点时间了解一下初始规则是如何解决的。  


### 题目
打家劫舍 II 和 打家劫舍 相比，题目只有一个变化。  
**这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。**  
这个规则会带来怎样的影响呢？  
如果按照原来的解法，最要命的问题就是**无法确定是否即抢了第一家又抢了最后一家**。  
那么，要怎么保证抢了第一家就不抢最后一家呢？  

### 分析
先简化一下问题，不考虑数字大小。  
* 例子1：  
数组长度2，数字为ab。  
这个例子，就算是初始规则下，也只有两种选择a或者b。  

* 例子2：  
数组长度3，数字为abc。  
加入新规则，如果先选择a，那么c会被新加规则排除掉，剩下ab用初始规则选择。  
而如果选择c，那么a会被新加规则排除掉，剩下bc用初始规则选择。  
而ab，bc用初始规则怎么选，像例子1一样。  

* 例子3：  
数组长度4，数字为abcd。看一下有什么选择方案。  
ac，~~ad~~（被新规则拒绝）,bd，共2种。  
那么，  
如果先选择a，那么d会被新加规则排除掉，在abc之间用初始规则选择。   
如果先选择d，那么a会被新加规则排除掉，在bcd之间用初始规则选择。   
注意这里不是像例子2，而是用初始规则，  
即：  
abc -> ac或者b。  
bcd -> bd或者c。  
说来说去，因为新规则的原因，不能即选a又选d，那么再在这两种里再选出最优解就ok了。  

* 例子4：  
再验证一次看看。  
数组长度5，数字为abcde，选择方案为：  
ac，ad，bd，be，ce共5种。  
那么，掐头去尾之后：  
abcd -> ac，ad，bd。  
bcde -> bd，be，ce。  
完美覆盖所有选择方案。  

似乎这个思路可行。  


### 思路  
1. 要把数组分成两个，即一个不包含nums.size() - 1（注释为head），另一个不包含0（注释为tail）。  
2. 按照初始规则解题思路，对这两个数组分别计算奇数和/偶数和。  
3. 最后对这两组奇数和/偶数和共计4个和求max。  
4. 优化一下使用一次循环处理。  
5. 注意在数组只有一个元素时，由于我的优化处理产生了新的边界问题。  


### 答题
为了方便对比，先看一下初始规则的答题。  
```C++
int rob(vector<int>& nums)
{
	int sumOdd = 0;
	int sumEven = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i % 2 == 0)
		{
			sumOdd = max(sumOdd, sumEven);
			sumEven += nums[i];
		}
		else
		{
			sumEven = max(sumOdd, sumEven);
			sumOdd += nums[i];
		}
	}
	return max(sumOdd, sumEven);
}
```

打家劫舍 II 的答题。  

```C++
int rob(vector<int>& nums)
{
	if (nums.size() == 1) return nums[0];

	int sumOdd[2] = {0, 0};	// 0 == head, 1 == tail
	int sumEven[2] = { 0, 0 };
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (i == 0 && j == 1) continue;	// head only
			if (i == nums.size() - 1 && j == 0) continue;	// tail only
			if (i % 2 == 0)
			{
				sumOdd[j] = max(sumOdd[j], sumEven[j]);
				sumEven[j] += nums[i];
			}
			else
			{
				sumEven[j] = max(sumOdd[j], sumEven[j]);
				sumOdd[j] += nums[i];
			}
		}
	}

	for (int j = 0; j < 2; j++)
	{
		sumOdd[j] = max(sumOdd[j], sumEven[j]);
	}
	return max(sumOdd[0], sumOdd[1]);
}
```

完成。  


### 下集预告：  
[【打家劫舍 III】代码简洁易懂 III](https://leetcode-cn.com/problems/house-robber-iii/solution/da-jia-jie-she-iii-dai-ma-jian-ji-yi-dong-iii-by-i/)  



### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)
### 题目
给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

说明:  
不允许旋转信封。

示例:  
```
输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3 
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
```

### 思路

* 降维
> 一开始我考虑使用按照w升序对信封排列，h也没多做考虑，直接也是升序排列。  
> 这个用例帮我发现了问题。  
> ```
> 输入: envelopes = [[4,5],[4,6],[6,7],[2,3],[1,1]]  
> 输出: 4
> ```
> 
> w升序，h升序：   
> [[1,1],[2,3],[4,5],[4,6],[6,7]]  
> 降维之后：[1,3,5,6,7]  
> 实际5和6的w是相同的，不应该被计算。  
> 
> 所以考虑w相同时，对h降序。
> w升序，h降序：  
> 降维之后：[1,3,6,5,7]  
> 把h改成降序之后，最长上升子序列的算法特性会对相同w的数据进行排除。  
> 6和5因为逆序的关系，所以不会同时被计算。  



* 最长上升子序列
> [longest-increasing-subsequence 最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)  
> 
> 一个简单的做法：  
> 
> 求一个数组中最长上升子序列，对数组中的数字依次拿出来放入新数组，重新进行摆放，  
> 摆放的要求是：  
> * 如果比数组中已经排好的数字小，则替换比你大的那个数字，数组长度不增加。  
> * 如果比数组中所有数字都大，排在队尾，数组长度增加1。 
>> 可以使用二分查找法来优化寻找需要替换数字的索引位置， 
> 
> 因此，这个新数组有以下属性：
> 1. 这个数组的长度就是这个数列最长上升子序列。  
> 2. 因为数组中的数字都在不断替换成更优，但是不影响之前保存的最长长度。  
> 3. 而因为替换过更优，再后续到来的数字，能够以更优的数字来计算新的最长长度。  



### 转化为代码
```C++
int maxEnvelopes(vector<vector<int>>& envelopes) 
{
	if (envelopes.size() <= 1) return envelopes.size();

	sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b)
	{
		if (a[0] == b[0]) return a[1] > b[1];
		return a[0] < b[0];
	});

	vector<int> vec;
	for (int i = 0; i < envelopes.size(); i++)
	{
		int h = envelopes[i][1];
		if (vec.empty() || h > vec.back())
		{
			vec.push_back(h);
		}

		for (int j = 0; j < vec.size(); j++)
		{
			if (h <= vec[j])
			{
				vec[j] = h;
				break;
			}
		}
	}

	return vec.size();
}
```  

计算最长上升子序列部分，使用从前到后遍历的方法，帮助理解。  
可以使用这个用例来观察和理解。  
```
输入: envelopes = [[1,1],[2,2],[3,3],[10,10],[11,11],[12,5],[12,4],[13,5],[20,6]]  
输出: 6
```

### 答题
使用二分查找，稍微优化一下：  
```C++
int maxEnvelopes(vector<vector<int>>& envelopes)
{
	if (envelopes.size() <= 1) return envelopes.size();

	sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b)
	{
		if (a[0] == b[0]) return a[1] > b[1];
		return a[0] < b[0];
	});

	int ans = 0;
	vector<int> vec(envelopes.size(), INT_MAX);
	for (auto &e : envelopes)
	{
		int low = 0;
		int high = envelopes.size() - 1;
		while (high > low)
		{
			int mid = low + (high - low) / 2;
			if (vec[mid] >= e[1]) high = mid;
			else low = mid + 1;
		}

		vec[low] = e[1];
		ans = max(ans, low);
	}
	return ans + 1;
}
```

> 二分查找部分还可以直接使用lower_bound  
> ```C++
> int ans = 0;
> vector<int> vec(envelopes.size(), INT_MAX);
> for (auto &e : envelopes) 
> {
> 	auto it = lower_bound(vec.begin(), vec.end(), e[1]);
> 	*it = e[1];
> 	ans = max(ans, int(it - vec.begin()));
> }
> return ans + 1;
> ```


完成。

### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)
### 思路
1. 将输入的数组按照**某个顺序**排序，然后按顺序组合就是最大数。

2. 这个顺序的目的是实现**组合后较大的数字在**前面。

3. 所以排序的比较算法应该是对**组合后的数字**进行比较。

4. 通过计算进行比较的两个数字的位数，**交叉相乘再相加** (a * (b 的位数) + b) ，实现将两个数字组合到一起。


### 答题
使用数学方法计算，4ms，打败99.78%。  
```C++
string largestNumber(vector<int>& nums) 
{
	auto f_sort = [](const int &a, const int &b)
	{
		long long n_a = 10;
		while (a / n_a) n_a *= 10;
		long long n_b = 10;
		while (b / n_b) n_b *= 10;
		long long r_a = (long long)a * n_b + (long long)b;
		long long r_b = (long long)b * n_a + (long long)a;
		return r_a < r_b;
	};

	sort(nums.rbegin(), nums.rend(), f_sort);

	string ans;
	for (auto n : nums)
	{
		ans = (ans == "0") ? to_string(n) : ans + to_string(n);
	}
	return ans;
}
```

转换成字符串之后比较也可以，还规避了int范围的问题，但是效率会差一点。  
```C++
string largestNumber(vector<int>& nums)
{
	sort(nums.rbegin(), nums.rend(), [](const int& a, const int& b)
	{
		string sa = to_string(a);
		string sb = to_string(b);
		return sa + sb < sb + sa;
	});

	string ans;
	for (auto n : nums)
	{
		ans = (ans == "0") ? to_string(n) : ans + to_string(n);
	}
	return ans;
}
```


### 测试用例
1. 位数不同相比较
```
输入: [121,12]
输出: 12121
```

2. 全0处理
```
输入: [0,0]
输出: 0
```

3. int越界
```
输入: [999999998,999999997,999999999]
输出: 999999999999999998999999997
```



### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)
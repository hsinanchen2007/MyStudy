[知乎@司南牧](https://www.zhihu.com/people/yuanmuou/activities)
```c++
 int maxSubArray(vector<int>& nums) {
	int len = nums.size();
	int result = nums[0];
	int sum = 0;
	for (size_t i = 0; i < len; i++)
	{
		if (sum<0)
		{
			sum = 0;
		}
		sum += nums[i];
		if (sum>result)
		{
			result = sum;
		}
	}
	return result;
}
```

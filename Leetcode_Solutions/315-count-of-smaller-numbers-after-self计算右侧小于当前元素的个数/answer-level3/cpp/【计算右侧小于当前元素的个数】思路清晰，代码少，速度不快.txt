
### 思路
1. 从后往前依次取出数字去排序
2. 使用二分查找找到新的数字排在第几位，就是比几个数字大
3. 然后将这个数字插入到该位置



### 答题
```C++
vector<int> countSmaller(vector<int>& nums) 
{
	if (nums.empty()) return {};
	if (nums.size() == 1) return { 0 };

	vector<int> counts(nums.size(), 0);
	vector<int> sort_nums;

	sort_nums.push_back(nums[nums.size() - 1]);
	size_t i = nums.size() - 2;
	do
	{
		auto it = lower_bound(sort_nums.begin(), sort_nums.end(), nums[i]);
		counts[i] = it - sort_nums.begin();
		sort_nums.insert(it, nums[i]);
	} while (i-- != 0);
	
	return counts;
}
```





### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)
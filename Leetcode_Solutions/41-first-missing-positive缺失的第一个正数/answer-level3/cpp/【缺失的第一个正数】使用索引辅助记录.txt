### 思路
1. 使用索引当做记录的手段
2. 先遍历一遍把数字按照索引放好
   * 注意交换后，新的数字的处理
   * 注意有重复数字时的处理
3. 再遍历一遍找到缺失的数字

### 答题
```C++
int firstMissingPositive(vector<int>& nums) 
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] >= 1 && nums[i] < nums.size())
		{
			int t = nums[i] - 1;
			if (nums[i] != nums[t])
			{
				swap(nums[i], nums[t]);
				i -= (t > i);
			}
		}
	}
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] != i + 1) return i + 1;
	}
	return nums.size() + 1;
}
```

### 测试用例
```
输入：[-1,4,2,1,9,10]
输出：[3]
```
```
输入：[2,2,2,2,2]
输出：[1]
```

### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)
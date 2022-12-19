看了大部分解决都提到了双指针，一开始并未想到用双指针，而是类似插入排序的数据搬移。
记录一个跳跃个数s的变量，循环遍历数组，假如碰到重复的，则跳跃个数加1，如果不是重复的，则说明此元素之前s个位置是冗余位置，则此元素可以前进s个位置。
循环一遍，即把每个不重复元素的位置排列好

代码：
```
int removeDuplicates(vector<int>& nums) {
	int skip_c = 0;
    int s = nums.size();
	for (int i = 1; i < s; i ++)
	{
		if (nums[i] == nums[i - 1])
		{
			skip_c++;
		}
		else
		{
			nums[i - skip_c] = nums[i];
		}
	}

	return s - skip_c;
    }
```

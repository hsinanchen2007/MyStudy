### 解题思路
执行用时 :116 ms, 在所有 cpp 提交中击败了92.92%的用户
内存消耗 :14.6 MB, 在所有 cpp 提交中击败了89.58%的用户

本题实质还是一个三重循环查找，只不过将暴力的内部二重循环搜索改为了双指针滑动搜索，从而避免了多次重复冗余查找。代码核心点包括：
（1）边界条件的设计：size以及迭代器判断
（2）输出冗余的处理：对重复的数字直接跳过

### 代码

```cpp
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int target = 0, val = 0;
		vector<int> tmp;
		vector<int>::iterator beginIter, endIter;
		vector<vector<int>> ret;

		if (nums.size() <= 2)
			return ret;

		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++)
		{
			target = 0 - nums[i];
			if (target < 0)
				break;

			beginIter = nums.begin() + i + 1;
			endIter = nums.end() - 1;

			while (beginIter < endIter)
			{
				int begin = *beginIter, end = *endIter;
				val = begin + end;
				if (val == target)
				{
					tmp.push_back(nums[i]);
					tmp.push_back(*beginIter);
					tmp.push_back(*endIter);
					ret.push_back(tmp);
					tmp.clear();
					while (beginIter < endIter && *beginIter == begin)
						beginIter++;
					while (beginIter < endIter && *endIter == end)
						endIter--;

				}
				else if (val < target)
				{
					beginIter++;
				}
				else
				{
					endIter--;
				}
			}

			while (i < nums.size() - 2 && nums[i] == nums[i + 1])
				i++;
		}

		return ret;
	}
};
```
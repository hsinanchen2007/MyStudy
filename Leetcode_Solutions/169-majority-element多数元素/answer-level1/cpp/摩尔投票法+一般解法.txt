一般解法，使用map存储数字出现的次数
```cpp
class Solution
{
public:
	int majorityElement(vector<int>& nums)
	{
		unordered_map<int, int> m;
		int n = nums.size();
		for (auto num : nums)
		{
			if (m.find(num) != m.end())
			{
				m[num] ++;
			}
			else
			{
				m[num] = 1;
			}
			if (m[num] > n / 2)
			{
				return num;
			}
		}
		return -1;
	}
};
```
摩尔投票法：
```cpp
class Solution
{
public:
	int majorityElement(vector<int>& nums)
	{
		int res = nums[0];
		int count = 1;
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] == res)
			{
				count++;
			}
			else
			{
				count--;
				/*小于0再重置，是因为前面两个不同的都要消去*/
				if (count < 0)
				{
					res = nums[i];
					count = 1;
				}
			}
		}
		return res;
	}
};
```
时间复杂度O(max(nums.size(),nums[i]区间长度))，空间复杂度O(nums[i]区间长度)
```cpp
class Solution 
{
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
	{
		vector<int> cnt(101, 0);
		vector<int> res(nums.size(), 0);
		for (auto n : nums)
		{
			cnt[n] ++;
		}
		/*求前缀和*/
		for (int i = 1; i < 101; ++i)
		{
			cnt[i] += cnt[i - 1];
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			/*如果nums[i]为0，那么res[i]本就该为0，即初始化值*/
			if (nums[i])
			{
				res[i] = cnt[nums[i] - 1];
			}
		}
		return res;
	}
};
```
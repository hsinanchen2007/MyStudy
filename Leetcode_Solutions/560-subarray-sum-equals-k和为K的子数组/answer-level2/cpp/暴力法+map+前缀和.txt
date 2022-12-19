我觉得暴力法一直是很重要，甚至是最重要最基础的，因为它至少说明你有办法解决这个问题，即使办法不是那么好
如果是面试，先拿出来个暴力法，再一步步去优化，肯定比直接背出来个最优解法好

暴力法+前缀和，时间复杂度O(n^2)，空间复杂度O(1)
这道题的暴力法，至少说明你会通过循环来遍历所有子数组
```cpp
class Solution
{
public:
	int subarraySum(vector<int>& nums, int k)
	{
		int count = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			int sum = 0;
			for (int j = i; j < nums.size(); ++j)
			{
				sum += nums[j];
				if (sum == k)
				{
					count++;
				}
			}
		}
		return count;
	}
};
```
前缀和+map，时间复杂度O(n),空间复杂度O(n)
```cpp
class Solution
{
public:
	int subarraySum(vector<int>& nums, int k)
	{
		int count = 0;
		int sum = 0;
		unordered_map<int, int> dic;
		dic[0] = 1;
		for (int i = 0; i < nums.size(); ++i)
		{
			sum += nums[i];
			/*如果sum - k存在，说明从sum-k到sum这段的和就是k*/
			if (dic.find(sum - k) != dic.end())
			{
				count += dic[sum - k];
			}
			dic[sum] ++;
		}
		return count;
	}
};
```
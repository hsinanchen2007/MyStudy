集合I是给定的nums，其中数字范围为1~n，有缺失数字，也有重复
契合II是1~n，每个数字都有一个
两个集合的元素个数相等，范围相等。
集合I将元素作为下标互相访问，一定有缺失的几个数字无法被访问到，而其他元素必定被访问到
另外，第287题寻找重复数字，跟此题思路类似[287](https://leetcode-cn.com/problems/find-the-duplicate-number/)
```cpp
class Solution
{
public:
	vector<int> findDisappearedNumbers(vector<int>& nums)
	{
		for (auto n : nums)
		{
			/*注意可能某个下标现在已经是负数；因为下标重复，已经给对方数字乘过-1,*/
			nums[fabs(n) - 1] = -fabs(nums[fabs(n) - 1]);
		}
		vector<int>res;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] > 0)
			{
				res.push_back(i + 1);
			}
		}
		return res;
	}
};
```
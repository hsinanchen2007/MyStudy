
```
class Solution
{
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums)
	{
		//初始化，先假设所有数字均有大于其他数字
		vector<int> ret(nums.size(),nums.size()-1);
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = i + 1; j < nums.size(); ++j)
			{
				if (nums[i] == nums[j])
				{
					--ret[j];
					--ret[i];
				}
				else if (nums[i] > nums[j])
				{
					--ret[j];
				}
				else --ret[i];
			}
		}
		return ret;
	}
};
```

```
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int len = nums.size();
		int cha = 2147483640;
		int sums=0;
		for (int i = 0; i < len - 2; i++)
		{
			for (int j = i + 1; j < len - 1; j++)
			{
				for (int k = j + 1; k < len ; k++)
				{
					if (abs(nums[i] + nums[j] + nums[k] - target) < cha)
					{
						sums = nums[i] + nums[j] + nums[k];
						cha = abs(nums[i] + nums[j] + nums[k] - target);
					}
				}
			}
		}
		return sums;
	}
};
```

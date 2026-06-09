```
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int start = -1;
		int count = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] >= 1)
			{
				start = i;
				break;
			}
		}
		if (start == -1)return 1;
		for (int i = start; i < nums.size(); i++)
		{
			if (nums[i] != count)return count;
			if (i != nums.size() - 1)
			{
				if (nums[i + 1] == nums[i])
				{
					count--;
				}
			}
			count++;
		}
		return count;
	}
};
```

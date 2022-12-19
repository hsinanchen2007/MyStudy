```
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int len = nums.size();
		if (len == 0)return 0;
		if (nums[0] > target)return 0;
		for (int i = 0; i < len-1; i++)
		{
			if (nums[i] == target)
			{
				return i;
			}
			else if (target > nums[i] && target < nums[i + 1])
			{
				return i + 1;
			}
		}

		if (nums[len - 1] == target)
		{
			return len - 1;
		}
		else
		{
			return len;
		}
	}
};
```

```
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int mincha = 999999;
		int minflag = 0;
		for (int mid = 1; mid < nums.size() - 1; mid++)
		{
			int flag = 0;
			int cha = 999999;
			int str = 0, end = nums.size() - 1;
			while (str < mid&&mid < end)
			{
				int tempsum = nums[str] + nums[mid] + nums[end];
				int tempcha = tempsum > target ? tempsum - target : target - tempsum;
				if (tempcha < cha)
				{
					cha = tempcha;
					if (tempsum < target)
					{
						flag = 1;
					}
					else
					{
						flag = 0;
					}
				}
				if (tempsum < target)
				{
					str++;
				}
				else
				{
					end--;
				}
			}
			if (mincha > cha)
			{
				mincha = cha;
				minflag = flag;
			}

		}
		if (minflag)
		{
			return target - mincha;
		}
		else
		{
			return target + mincha;
		}

	}
};
```

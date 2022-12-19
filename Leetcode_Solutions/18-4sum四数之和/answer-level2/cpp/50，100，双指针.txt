### 解题思路
思路，双指针，只是在三数之和基础上嵌套了一层循环

### 代码

```cpp
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		if (nums.size() < 4)
			return res;
		//去重复用
		set<set<int>> rr;
		int rrsize = 0;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++)
		{
			//至少要有一个解才能退出
			if (nums[i] > target / 4)
				return res;
			if (i - 1 >= 0 && nums[i] == nums[i - 1])
				continue;
			for (int j = i + 1; j < nums.size(); j++)
			{
				int l = j + 1, r = nums.size() - 1;
				while (l < r)
				{
					int sum = nums[i] + nums[j] + nums[l] + nums[r];
					if (sum == target)
					{
						rr.insert({ nums[i] , nums[j] , nums[l] , nums[r] });
						if (rr.size() > rrsize)
						{
							rrsize++;
							res.push_back({ nums[i] , nums[j] , nums[l] , nums[r] });
						}
						r--; l++;
					}
					if (sum > target)
						r--;
					//update l r
					if (sum < target)
						l++;

				}
			}
		}

		return res;

	}
};

```
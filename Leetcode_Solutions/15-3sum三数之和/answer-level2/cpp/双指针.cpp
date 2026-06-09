### 解题思路
此类问题先排序能省去不少步骤
先确定第一个数，对剩下两个数采用双指针，一次循环
两个注意点，第一个数若是大于0，退出
第一个数与它的前一个数相同（重复情况），跳过

### 代码

```cpp

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() < 3)
			return res;
		sort(nums.begin(),nums.end());
		set<set<int>> res_set;

		int setsize = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0)
				break;
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			//使用双指针减少循环次数
			int l = i + 1, r = nums.size() - 1;
			while (l < r)
			{
				//注意判断条件，和为0退出，和小了，l右移，大了，r左移，
				int sum = nums[i] + nums[l] + nums[r];
				if (sum == 0)
				{
					//判断重复否
					res_set.insert({ nums[i],nums[l],nums[r] });
					if (res_set.size() > setsize)
					{
						setsize++;
						res.push_back({ nums[i],nums[l],nums[r] });
					}
					l++; r--;
				}
				else
					if (sum < 0)
						l++;
					else
						r--;

			}
		}
		return res;
	}
};
```
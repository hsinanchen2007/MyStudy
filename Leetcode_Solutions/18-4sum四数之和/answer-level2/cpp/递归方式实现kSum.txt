twoSum采用双指针实现，(k)_Sum可以看作遍历nums中每个元素作为target的(k-1)_Sum。

```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        return kSum(nums, target, 4);    
    }

	vector<vector<int>> kSum(vector<int>& nums, int target, int k) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> results;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i>0 && nums[i] == nums[i - 1])
				continue;
			int tmp_target = target - nums[i];
			vector<int> tmp_nums(nums.begin() + i + 1, nums.end());
			// 迭代
			vector<vector<int>> tmp_results;
			if (k-1 != 2)
			{
				tmp_results = kSum(tmp_nums, tmp_target, k-1);
			}
			else
				tmp_results = twoSum(tmp_nums, tmp_target);
			for (int j = 0; j<tmp_results.size(); j++)
			{
				vector<int> tmp_result = tmp_results[j];
				tmp_result.insert(tmp_result.begin(), nums[i]);
				results.push_back(tmp_result);
			}
		}
		return results;
	}
	vector<vector<int>> twoSum(vector<int> &nums, int target)
	{
		vector<vector<int>> results;

		sort(nums.begin(), nums.end());
		int start = 0, end = nums.size() - 1;
		while (start < end)
		{
			if (nums[start] + nums[end] == target)
			{
				vector<int> result;
				result.push_back(nums[start]);
				result.push_back(nums[end]);
				start++, end--;
				// 跳过重复元素
				while (nums[start] == nums[start - 1] && start < end)
					start++;
				while (nums[end] == nums[end + 1] && start < end)
					end--;

				results.push_back(result);
			}
			else if (nums[start] + nums[end] < target)
			{
				start++;
			}
			else
				end--;
		}
		return results;
	}
};
```

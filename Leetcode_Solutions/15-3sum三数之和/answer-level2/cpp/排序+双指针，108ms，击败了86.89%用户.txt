### 解题思路


### 代码

```cpp
class Solution {
public:
void TwoSum(vector<int> nums, int target, int StartIndex, vector<vector<int>>& results) {
	int left = StartIndex;
	int right = nums.size() - 1;
	vector<int> result;
	while (left < right) {//双指针
		if (nums[left] + nums[right] < target)left++;
		else if (nums[left] + nums[right] > target)right--;
		else {
			result.push_back(nums[left]);
			result.push_back(-target);
			result.push_back(nums[right]);

			results.push_back(result);
			left++; right--;
			while (left < right && nums[left] == nums[left - 1])//排除掉相同的集合情况
			{
				left++;
			}
			while (left < right && nums[right] == nums[right + 1])
			{
				right--;
			}
			result.clear();
		}
	}
}

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> results;
	if (nums.size() <= 2)return results;//注意
	sort(nums.begin(), nums.end());
	
	for (int i = 0; i < nums.size() - 2; i++) {
		if (i>=1&&nums[i] == nums[i-1])//当该数已经判断过后，遇到相同的数就不再判断
		{
			continue;
		}
		TwoSum(nums, -nums[i], i + 1, results);
	}
	return results;
}


};
```
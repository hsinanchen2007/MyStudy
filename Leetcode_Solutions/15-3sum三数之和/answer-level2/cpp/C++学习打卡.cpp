### 解题思路
排序+双指针

### 代码

```cpp
class Solution {
private:
	void searchAndPush(vector<vector<int>>&ans, vector<int>& nums, int left, int right, int target) {
		while (left < right) {
			int curSum = nums[left] + nums[right];
			if (curSum < target) { left++; }
			else if (curSum > target) { right--; }
			else {
				ans.push_back({ -target,nums[left],nums[right] });
				int curLeftNum = nums[left], curRightNum = nums[right];
				while (left < right && nums[++left] == curLeftNum) {}
				while (left < right && nums[--right] == curRightNum) {}
			}
		}
		return;
	}

public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() <= 2) { return {}; }
		sort(nums.begin(), nums.end());
		vector<vector<int>>ans;
		int lastUseNum = INT_MAX;
		//若 nums[i]>0：因为已经排序好，所以后面不可能有三个数加和等于0，直接返回结果。
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == lastUseNum) { continue; }
			if (nums[i] > (0 / 3)) { break; }
			searchAndPush(ans, nums, i + 1, nums.size() - 1, -nums[i]);
			lastUseNum = nums[i];
		}
		return ans;
	}
};
```
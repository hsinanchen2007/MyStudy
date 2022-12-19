### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		if (nums.size() == 0) return 0;
		int count = 0;
		sort(nums.begin(), nums.end());
		//vector<int>::iterator it = unique(nums.begin(), nums.end());
		//if (it != nums.end()) nums.erase(it, nums.end());
		int temp = -20;
		for (int i = 0; i < nums.size() - 1; i++) {
			
			for (int j = i + 1; j < nums.size(); j++) {
				if (abs(nums[j] - nums[i]) == k&&temp!=nums[i]) {
					count++;
					temp = nums[i];
					break;
				}
				if ((nums[j] - nums[i]) > k||nums[i]==temp) break;
			}
			if (nums[i] == nums[i + 1]) i++;

		}
		return count;
	}
};
```
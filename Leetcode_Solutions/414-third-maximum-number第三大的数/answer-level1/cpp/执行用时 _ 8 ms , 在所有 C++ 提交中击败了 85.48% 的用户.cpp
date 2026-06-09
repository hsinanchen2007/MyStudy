### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	int thirdMax(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int>::iterator it;
		it = unique(nums.begin(), nums.end());
		if (it!=nums.end()) {
			nums.erase(it, nums.end());
		}
		int n = nums.size();
		if (nums.size() < 3) return nums[n - 1];
		else return nums[n - 3];
	}
};
```
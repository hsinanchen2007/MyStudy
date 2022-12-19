### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0) { return 0; }

		vector<int> count(nums.size(), 1);
		for (int i = 1; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (nums[j]<nums[i] && count[j] + 1>count[i]) {
					count[i] = count[i] + 1;
				}
			}
		}
		int maxLength = 1;
		for (int k = 0; k < count.size(); k++) {
			if (maxLength < count[k]) {
				maxLength = count[k];
			}
		}
		return maxLength;
	}
};
```
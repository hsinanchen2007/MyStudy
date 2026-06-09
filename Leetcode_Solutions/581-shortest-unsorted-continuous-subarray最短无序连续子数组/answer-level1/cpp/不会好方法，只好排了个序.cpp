```C++ []
class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		vector<int> tmp(nums);
		sort(tmp.begin(), tmp.end());
		int l = 0, r = nums.size() - 1;
		while (l < nums.size() && nums[l] == tmp[l])
			l++;
		while (r > -1 && nums[r] == tmp[r])
			r--;
		if (l < nums.size())
			return r - l + 1;
		return 0;
	}
};
```

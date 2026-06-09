两个指针一前一后包着 直观做法 但是超时了
```
class Solution {
public:
	int sum(const vector<int> &nums, int l, int r) {
		int res = 0;
		for (int i = l; i <= r; i ++) {
			if ((nums[i] % 2) != 0) {
				res ++;
			}
		}
		return res;
	}
	int numberOfSubarrays(vector<int>& nums, int k) {
		int n = nums.size();
		if (n < 1) { 
			return n;
		}
		int l = 0, r = -1;
		int res = 0;
		while (l < n) {
			if (r + 1 < n && sum(nums, l, r + 1) <= k) {
				r ++;
			} else {
				l ++;
				r = 0;
			}
			if (sum(nums, l, r) == k) {
				res ++;
			}
		}
		return res;
	}
};
```

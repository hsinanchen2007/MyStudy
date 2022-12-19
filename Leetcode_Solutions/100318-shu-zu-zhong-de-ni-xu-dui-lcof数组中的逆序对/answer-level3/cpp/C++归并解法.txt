参考[@liweiwei1419](/u/liweiwei1419/)大佬的解法，用C++写了归并排序的解法
```
class Solution {
public:
	int reversePairs(vector<int>& nums) {
		int res = 0;
		vector<int> tmp(nums.size(), 0);
		Mergesort(nums, 0, nums.size() - 1, tmp, res);
		return res;
	}
	void Mergesort(vector<int>& nums, int l, int r, vector<int>& tmp, int& res) {
		if (l < r) {
			int mid = l + (r - l) / 2;
			Mergesort(nums, l, mid, tmp, res);
			Mergesort(nums, mid + 1, r, tmp, res);
			int lpos = l, rpos = mid + 1, tpos = l;
			while (lpos <= mid && rpos <= r) {
				if (nums[rpos] < nums[lpos]) {
					tmp[tpos++] = nums[rpos++];
					res += mid - lpos + 1;
				}
				else {
					tmp[tpos++] = nums[lpos++];
				}
			}
			while (lpos <= mid) {
				tmp[tpos++] = nums[lpos++];
			}
			while (rpos <= r) {
				tmp[tpos++] = nums[rpos++];
			}
			while (l <= r) {
				nums[l] = tmp[l];
				l++;
			}
		}
	}
};
```
```cpp
class Solution {
public:
	void partition(vector<int>& nums, int l, int r) {
		if (l >= r) return;
		swap(nums[r], nums[l + rand() % (r - l + 1)]); // 基于随机的划分

		int i = l, pivot = nums[r];
		for (int j = l; j < r; ++j)
			if (nums[j] <= pivot) swap(nums[i++], nums[j]);
		swap(nums[i], nums[r]);

		partition(nums, l, i - 1);
		partition(nums, i + 1, r);
	}

	vector<int> sortArray(vector<int>& nums) {
		partition(nums, 0, nums.size() - 1);
		return nums;
	}
};
```
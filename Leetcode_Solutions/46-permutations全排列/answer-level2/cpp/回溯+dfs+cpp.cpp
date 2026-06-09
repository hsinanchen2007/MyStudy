比较常规的一题
第一种方法：
```
void permute(vector<int>& nums, vector<vector<int>>& ans, int k) {
	if (k == nums.size()) {
		ans.push_back(nums);
		return;
	}
	for (int i = k; i < nums.size(); i++) {
		swap(nums[k], nums[i]);
		permute(nums, ans, k + 1);
		swap(nums[k], nums[i]);
	}
}
vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> ans;
	permute(nums, ans, 0);
	return ans;
}
```
第二种方法：使用库函数
先对数字排序，然后使用next_permutation函数

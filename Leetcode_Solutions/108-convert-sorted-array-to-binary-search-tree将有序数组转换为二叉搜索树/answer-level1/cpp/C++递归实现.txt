与[傅里叶变身老兄的解答](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/solution/cdi-gui-shi-xian-by-fu-li-xie-bian-she-yymodya3tg/)基本相同，只是获取左右子数组的方式不同。


```cpp
TreeNode* sortedArrayToBST(vector<int>& nums) {
	if (nums.empty()) return NULL;
	int mid_idx = nums.size() / 2;
	TreeNode* root = new TreeNode(nums[mid_idx]);
	vector<int> left(nums.begin(), nums.begin() + mid_idx);
	root->left = sortedArrayToBST(left);
	vector<int> right(nums.begin() + mid_idx + 1,nums.end());
	root->right = sortedArrayToBST(right);
	return root;
}
```

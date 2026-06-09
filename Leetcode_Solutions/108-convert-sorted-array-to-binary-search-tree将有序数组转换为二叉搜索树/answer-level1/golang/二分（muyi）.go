### 解题思路

数组是有序的，并且二叉搜索树是平衡的，想到二分

- mid为root
- [left: mid-1]为左子树
- [mid+1: right]为右子树

### 代码

cpp

```cpp
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {

        if (nums.size() == 1) return new TreeNode(nums[0]);
        if (nums.size() == 0) return NULL;
        int mid = (nums.size() - 1) >> 1;
        auto root = new TreeNode(nums[mid]);
        vector<int> lv(nums.begin(), nums.begin() + mid);
        root->left = sortedArrayToBST(lv);
        vector<int> rv(nums.begin() + mid + 1, nums.end());
        root->right = sortedArrayToBST(rv);
        return root;
    }
};
```

go

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func SortedArrayToBST(nums []int) *TreeNode {
	return dfs(nums)
}

func dfs(nums []int) *TreeNode {
	if len(nums) == 0 {
		return nil
	}
	mid := len(nums) / 2
	root := &TreeNode{Val: nums[mid]}
	root.Left = dfs(nums[:mid])
	root.Right = dfs(nums[mid+1:])
	return root
}
```

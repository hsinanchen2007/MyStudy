```
/**

[1,2, 3]
root->val　< L, root及左枝剪掉，右枝提升为root; 
[1,2,3] 
:L <= roor->val <= R, 正常修剪
[1,2,3]
root->val > R ,root及右枝剪掉，左枝提升为root.
*/
func trimBST(root *TreeNode, L int, R int) *TreeNode {
	if root == nil {
		return root
	}
	if root.Val > R {
		return trimBST(root.Left, L, R)
	}
	if root.Val < L {
		return trimBST(root.Right, L, R)
	}
	root.Left = trimBST(root.Left, L, R)
	root.Right = trimBST(root.Right, L, R)
	return root
}
```

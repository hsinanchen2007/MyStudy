### 解题思路
此处撰写解题思路

### 代码

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func rangeSumBST(root *TreeNode, L int, R int) int {
    
	sum := 0
	if root == nil || (L == 0 && R == 0) {
		return sum
	}

	if root.Val >= L && root.Val <= R {
		sum += root.Val
	}

	sum += rangeSumBST(root.Left, L, R)
	sum += rangeSumBST(root.Right, L, R)

	return sum
}
```
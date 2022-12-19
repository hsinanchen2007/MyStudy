### 解题思路
Golang递归求解

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
func getHeight(node *TreeNode) int{

	// 计算节点的高度
	if node == nil {
		return -1
	}
	l := getHeight(node.Left)
	r := getHeight(node.Right)
	if l > r {
		return l + 1
	}else {
		return r + 1
	}
}

func isBalanced(root *TreeNode) bool {

	if root == nil {
		return true
	}
	return math.Abs(float64(getHeight(root.Left) - getHeight(root.Right))) <= 1 && isBalanced(root.Left) && isBalanced(root.Right)
}
```
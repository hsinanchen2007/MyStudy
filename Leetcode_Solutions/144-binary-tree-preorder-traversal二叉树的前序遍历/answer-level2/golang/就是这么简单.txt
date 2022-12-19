```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func perOrder(t *TreeNode,s *[]int) {
	*s = append(*s,t.Val)

	if t.Left != nil {
		perOrder(t.Left,s)
	}
	if t.Right != nil {
		perOrder(t.Right,s)
	}

}

func preorderTraversal(root *TreeNode) []int {
	var res []int
	if root == nil {
		return res
	}

	perOrder(root,&res)
	return res
}
```

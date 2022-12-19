### 解题思路

非递归右序，获取数组后组织新树

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
func increasingBST(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}

	var stack []*TreeNode

	var res []int
	node := root
	for len(stack) > 0 || node != nil {
		if node != nil {
			stack = append(stack, node)
			node = node.Left
			continue
		}

		n := stack[len(stack)-1]
		res = append(res, n.Val)
		stack = stack[:len(stack)-1]
		node = n.Right
	}

	pre := &TreeNode{res[0], nil, nil}
	tmp := pre
	for _, v := range res[1:] {
		next :=  &TreeNode{v, nil, nil}
		tmp.Right = next
		tmp = next
	}
	return pre
}
```
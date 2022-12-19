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
func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	var r1 []int
	var r2 []int
	leaf(root1, &r1)
	leaf(root2, &r2)

	if len(r1) != len(r2) {
		return false
	}

	index := 0
	for index < len(r1) {
		if r1[index] != r2[index] {
			return false
		}
		index++
	}

	return true
}

func leaf(root *TreeNode ,num *[]int) {
	if root == nil {
		return
	}
	if root.Left == nil && root.Right == nil {
		*num = append(*num, root.Val)
	}

	leaf(root.Left, num)
	leaf(root.Right, num)
}
```
### 解题思路
此处撰写解题思路
此题核心是要清楚叶子节点是指左右子树均为nil的节点
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
func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	res := math.MaxInt32
	iter_min_depth(root, 1,&res)
	return res
}

func iter_min_depth(root *TreeNode, depth int, min *int) {
	if root.Left == nil && root.Right == nil {
		if depth < *min {
			*min = depth
		}
		return
	}
	if root.Right != nil {
		iter_min_depth(root.Right, depth+1, min)
	}
	if root.Left != nil {
		iter_min_depth(root.Left, depth+1, min)
	}
}


```
### 解题思路
跟《100. 相同的树》差不多的解法

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
func isSymmetric(root *TreeNode) bool {
    if root == nil {
		return true
	}
	return isMirrorTree(root.Left, root.Right)
}

func isMirrorTree(p *TreeNode, q *TreeNode) bool {
	// 都为空 证明已经遍历到最后一个节点都相等 return true
	if p == nil && q == nil {
		return true
	}
	// 只有一个节点为空 证明节点数不相等 return false
	if p == nil || q == nil {
		return false
	}
	// 节点都不为空 但值不同 return false
	if p.Val != q.Val {
		return false
	}
	return isMirrorTree(p.Left, q.Right) && isMirrorTree(p.Right, q.Left)
}
```
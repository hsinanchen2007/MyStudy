### 解题思路
递归比较节点是否相同，有三种情况：
1、节点都为空 证明遍历到最后一个节点都相等 返回true
2、只有一个节点为空 证明节点数不相等 返回false
3、节点都不为空 但值不同 返回false

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
func isSameTree(p *TreeNode, q *TreeNode) bool {
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
	return isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
}
```
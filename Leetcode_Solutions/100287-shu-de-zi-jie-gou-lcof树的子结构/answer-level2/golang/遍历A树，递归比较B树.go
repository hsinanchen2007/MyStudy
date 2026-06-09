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
func dfs(A *TreeNode, B *TreeNode) bool {
	if B == nil {
		return true
	}
	if A != nil && A.Val == B.Val {
		return dfs(A.Right, B.Right) && dfs(A.Left, B.Left)
	}
	return false
}

func findStart(A *TreeNode, B *TreeNode) bool {
	if A == nil {
		return false
	}
	if A.Val == B.Val {
		if dfs(A, B) {
			return true
		}
	} else {
		return findStart(A.Left, B) || findStart(A.Right, B)
	}
	return false
}

func isSubStructure(A *TreeNode, B *TreeNode) bool {
	if A == nil || B == nil {
		return false
	}
	return findStart(A, B)
}
```
[github](https://github.com/temporaries/leetcode)


### 解题思路
这题其实也是对比两个树，根节点的左树与右树

1.左树的左节点=右树的右节点
2.左树的右节点=右树的左节点

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
	return dfs(root, root)
}

func dfs(p *TreeNode, q *TreeNode) bool {
	if p == nil || q == nil {
		return p == q
	}
	return dfs(p.Left, q.Right) && p.Val == q.Val && dfs(p.Right, q.Left)
}
```


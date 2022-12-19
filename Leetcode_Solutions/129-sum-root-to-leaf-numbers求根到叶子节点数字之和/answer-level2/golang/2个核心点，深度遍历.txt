### 解题思路
1. 在 `叶节点` 的时候 对 `res` 做加法，
2. 在下降到 `子节点` 的时候做乘法,每下降一层，`*10`

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
var res int

func sumNumbers(root *TreeNode) int {
	res = 0
	if root != nil {
		dfs(root, 0)
	}
    	return res
}

func dfs(root *TreeNode, sum int) {
	if root.Left == nil && root.Right == nil {
		res += sum*10 + root.Val//叶节点 做加法
		return
	}
	if root.Left != nil {
		dfs(root.Left, sum*10+root.Val) //子节点 乘以10
	}
	if root.Right != nil {
		dfs(root.Right, sum*10+root.Val)//子节点 乘以10
	}
}
```

[Go版本 Github](https://github.com/temporaries/leetcode)

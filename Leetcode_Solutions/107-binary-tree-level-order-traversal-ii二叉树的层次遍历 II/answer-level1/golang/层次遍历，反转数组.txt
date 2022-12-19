### 解题思路
直接在`103题`基础上，加个反转数组操作

### 代码
[github](https://github.com/temporaries/leetcode)

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 var res [][]int

func levelOrderBottom(root *TreeNode) [][]int {
	res = [][]int{}
	dfs(root, 0)

    l := len(res)
	end := l/2
	for i := 0; i < end; i++ {
		res[i], res[l-i-1] = res[l-i-1], res[i]
	}
	return res
}

func dfs(root *TreeNode, level int) {
	if root != nil {
		if len(res) == level {
			res = append(res, []int{})
		}
		res[level] = append(res[level], root.Val)
		dfs(root.Left, level+1)
		dfs(root.Right, level+1)
	}
}
```
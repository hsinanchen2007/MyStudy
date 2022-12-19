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
func findFrequentTreeSum(root *TreeNode) []int {
	var middle = make(map[int]int)
	var res []int
	var max int
	dfs(root,&middle, &res,&max)
	return res
}

func dfs(node *TreeNode, middle *map[int]int, res *[]int,max *int) int {
	if node == nil {
		return 0
	}
	left := dfs(node.Left, middle, res,max)
	right := dfs(node.Right, middle, res,max)
	cur := left + right + node.Val
	(*middle)[cur]++
	if (*middle)[cur] > *max {
		*res = []int{cur}
		*max = (*middle)[cur]
	} else if (*middle)[cur] == *max {
		*res = append(*res, cur)
	}
	return cur
}
```
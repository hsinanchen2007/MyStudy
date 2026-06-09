### 解题思路
1.思路还是 `前序遍历`
2.与 [112. 路径总和](https://leetcode-cn.com/problems/path-sum/) 一毛一样，多了个存路径的数组
3.继续套模板

[Go版本 Github](https://github.com/temporaries/leetcode)
[对应模板 Github](https://github.com/temporaries/leetcode/blob/master/templates/tree/preorder.go)
[本题完整代码 Github](https://github.com/temporaries/leetcode/blob/master/tree/0113.path-sum-ii)

### 代码

```golang
var res [][]int

func pathSum(root *TreeNode, sum int) [][]int {
	res = [][]int{}
	dfs(root, sum, []int{})
	return res
}

func dfs(root *TreeNode, sum int, stack []int) {
	if root == nil {
		return
	}
	stack = append(stack, root.Val)
	if root.Left == nil && root.Right == nil {
		if sum == root.Val {
			r := make([]int, len(stack))
			copy(r, stack)
			res = append(res, r)
		}
	}
	dfs(root.Left, sum-root.Val, stack)
	dfs(root.Right, sum-root.Val, stack)
}
```
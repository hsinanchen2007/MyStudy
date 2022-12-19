### 解题思路
为了使用这个思路（如果出现空节点后还有数字那么肯定是错的）而强行写代码！

### 代码

```golang
var res [][]int
// 入口
func isCompleteTree(root *TreeNode) bool {
	res = [][]int{}
	dfs(root, 0)

    //判断前几个结点是否饱和
	for i:=0; i<=len(res)-2; i++ {
		m := pow(2, i)
		if len(res[i]) != m {
			return false
		}
	}

//如果出现了空节点，那么后面如果还有数字，那么就肯定不是满二叉树
	m := 0
	for _, v := range res[len(res)-2] {
		if v == 999 {
			m = 1
		}
		if m == 1 && v != 999 {
			return false
		}
	}
	return true
}


// 层序遍历代码
func dfs(root *TreeNode, level int) {
	if len(res) == level {
		res = append(res, []int{})
	}
	if root != nil {
		res[level] = append(res[level], root.Val)
		dfs(root.Left, level+1)
		dfs(root.Right, level+1)
	} else {
		res[level] = append(res[level], 999)
	}
}
// 求整数幂函数
func pow(a, b int) int {
	if b == 0 {
		return 1
	}

	for b != 0 {
		a *= 2
		b--
	}
	return a / 2
}
```
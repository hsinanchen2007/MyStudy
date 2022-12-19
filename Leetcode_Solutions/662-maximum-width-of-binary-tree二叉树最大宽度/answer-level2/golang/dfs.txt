### 解题思路
此处撰写解题思路

### 代码

```golang
func widthOfBinaryTree(root *TreeNode) int {
	m := getDeep(root)
	p := make([][]int, m)
	dfs3(root, 0, p, m,0)
	var r int
	for k := 0; k < m; k++ {
		var start int
		var end int
		for i := 0; i < len(p[k]); i++ {
			if p[k][i] != -1 {
				start = p[k][i]
				break
			}
		}
		for i := len(p[k]) - 1; i >= 0; i-- {
			if p[k][i] != -1 {
				end = p[k][i]
				break
			}
		}
		if r < end-start+1 {
			r = end - start + 1
		}
	}

	return r
}

func dfs3(root *TreeNode, pos int, p [][]int, m int, val int ) {
	if pos >= m {
		return
	}
	if root == nil {
		p[pos] = append(p[pos], -1)
		return
	}
	p[pos] = append(p[pos], val)
	dfs3(root.Left, pos+1, p, m,val*2)
	dfs3(root.Right, pos+1, p, m,val*2+1)
}

func getDeep(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return 1 + max1(getDeep(root.Left), getDeep(root.Right))
}

func max1(a int, b int) int {
	if a > b {
		return a
	}
	return b
}
```
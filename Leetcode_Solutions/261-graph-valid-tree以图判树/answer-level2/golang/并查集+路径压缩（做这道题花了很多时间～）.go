### 解题思路
此处撰写解题思路

### 代码

```golang
func validTree(n int, edges [][]int) bool {
	f := make([]int, n)
	for i:=0;i<n;i++ {
		f[i] = i
	}

	for _, edge := range edges {
		root1 := search(f, edge[0])
		root2 := search(f, edge[1])
		if root1 == root2 {
			return false
		}

		f[root1] = root2
	}

	root := search(f, 0)
	for i:=1;i<n;i++ {
		if search(f, i) != root {
			return false
		}
	}

	return true
}

func search(f []int, i int) int {
    son := i
	for f[i] != i {
		i = f[i]
		search(f, i)
	}

    //路径压缩
    for son != i {
		tmp := f[son]
		f[son] = i
		son = tmp
	}

	return i
}
```
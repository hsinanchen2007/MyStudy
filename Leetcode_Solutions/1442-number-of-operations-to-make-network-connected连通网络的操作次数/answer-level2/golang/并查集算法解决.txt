
```
// 并查集实现
func makeConnected(n int, connections [][]int) int {
	line := len(connections)
	res := 0
	if (n-1) > line {
		return -1;
	}
	pre := make([]int, n)
	for i := 0; i < n; i++ {
		pre[i] = i
	}
	for i := 0; i < len(connections); i++ {
		union(connections[i][0], connections[i][1], pre)
	}
	for i := 0; i < n; i++ {
		if pre[i] == i {
			res++
		}
	}
	return res-1

}

func union(x, y int, p []int) {
	x_root := find(x, p)
	y_root := find(y, p)
	if x_root != y_root {
		p[x_root] = y_root
	}
}

func find(x int, p []int) int {
	r := x
	for p[r] != r {
		r = p[r]
	}
	i := x
	for i != r {
		j := p[i]
		p[i] = r
		i = j
	}
	return r
}

```
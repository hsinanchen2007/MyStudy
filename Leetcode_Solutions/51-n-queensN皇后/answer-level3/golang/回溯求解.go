4ms，3.6MB解决方案，使用矩阵层级遍历，每次向下搜索，-1表示搜索失败的节点

```
func metrix(n int) [][]int {
	var m = make([][]int, 0, n)
	for i := 0; i < n; i++ {
		m = append(m, make([]int, n, n))
	}
	return m
}

type point struct {
	x int
	y int
}

func solveNQueens(n int) [][]string {
	var (
		m   = metrix(n)
		ps  = make([]*point, n, n)
		res = make([][]string, 0, n)
	)
	for i := 0; i < n; {
		p, t := cal(m, i, n)
		if !t {
			if i == 0 {
				return res
			}
			// 回溯
			// 标记上一次的节点不可用
			i--
			p = ps[i]
			m[p.x][p.y] = -1
			continue
		}
		ps[i] = p
		i++
		if i == n {
			res = append(res, build(ps, n))
			i = restart(m, n, ps)
			if i == -1 {
				return res
			}
			m[ps[i].x][ps[i].y] = -1
		}
	}
	return res
}

// 自下向上寻找可用的新方案
func restart(m [][]int, n int, ps []*point) int {
	for i := n; i > 0; i-- {
		for j, v := range m[i-1] {
			if v == i && j > ps[i-1].y {
				return i - 1
			}
		}
	}
	return -1
}

// 查找当前层级可用的节点，并标记
func cal(m [][]int, i int, n int) (*point, bool) {
	j := findUnUsedFromLineI(m, i)
	if j == -1 {
		return nil, false
	}
	fillMetrix(m, j, i, n)
	return &point{i, j}, true
}

func findUnUsedFromLineI(m [][]int, i int) int {
	for k, v := range m[i] {
		if v == 0 || v > i {
			return k
		}
	}
	return -1
}

func fillMetrix(m [][]int, x, y, n int) {
	// 行标记
	for i, v := range m[y] {
		if v == 0 {
			m[y][i] = y + 1
		}
	}

    // 竖，斜线标记
	for j := y + 1; j < n; j++ {
		for i := 0; i < n; i++ {
			v := m[j][i]
			if v <= y && v > 0 {
				continue
			}
			if i == x || i-x == j-y || i-x == y-j {
				m[j][i] = y + 1
			} else {
				m[j][i] = 0
			}
		}
	}
}

// 构造字符串
func build(ps []*point, n int) []string {
	var res []string
	for _, p := range ps {
		l := bytes.Repeat([]byte("."), n)
		l[p.y] = byte('Q')
		res = append(res, string(l))
	}
	return res
}
```
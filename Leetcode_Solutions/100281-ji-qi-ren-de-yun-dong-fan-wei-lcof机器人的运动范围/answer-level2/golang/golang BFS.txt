### 解题思路

BFS

### 代码

```golang

func movingCount(m int, n int, k int) int {
	// m, n, k
	// 初始化访问数组
	visit := make([][]bool, m)
	for i := 0; i < m; i++ {
		visit[i] = make([]bool, n)
	}
	cnt := 0
	var walk func(int, int)
	var isVaildCell func(int, int) bool

	// 验证是否是一个有效的单元
	isVaildCell = func(x, y int) bool {
		if x < 0 || x >= m || y < 0 || y >= n {
			return false
		}
		cnt1, cnt2 := 0, 0
		for x != 0 {
			cnt1 += x % 10
			x /= 10
		}
		for y != 0 {
			cnt2 += y % 10
			y /= 10
		}

		if cnt1+cnt2 > k {
			return false
		}
		return true
	}

	walk = func(x, y int) {
		if !isVaildCell(x, y) || visit[x][y] {
			return
		}
		visit[x][y] = true
		cnt++

		walk(x+1, y)
		walk(x-1, y)
		walk(x, y+1)
		walk(x, y-1)
		return
	}
    walk(0,0)
	return cnt
}
```
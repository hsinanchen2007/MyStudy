

1. 数组模拟队列
2. 最后输出入队列所有节点的数量
3. 技巧：高位表示x，低位表示y（x*100 + y）因为x跟y的数据范围100以内

```
func movingCount(m int, n int, k int) int {
	vis := make([][]int, m)
	for i := 0; i < m; i++ {
		vis[i] = make([]int, n)
	}
	vis[0][0] = 1

	queue := make([]int, m*n+1)
	top := 0
	l := 1
	queue[top] = 0

	dx := []int{1, -1, 0, 0}
	dy := []int{0, 0, 1, -1}
	for top < l {
		x := queue[top] / 100
		y := queue[top] % 100
		top++

		for i := 0; i < 4; i++ {
			tempX := x + dx[i]
			tempY := y + dy[i]
			if tempX < 0 || tempX >= m || tempY < 0 || tempY >= n || vis[tempX][tempY] == 1 {
				continue
			}
			if sum(tempX)+sum(tempY) > k {
				continue
			}
			queue[l] = tempX*100 + tempY
			l++
			vis[tempX][tempY] = 1
		}
	}
	return l
}

func sum(x int) int {
	res := 0
	for x != 0 {
		res += x % 10
		x /= 10
	}
	return res
}
```

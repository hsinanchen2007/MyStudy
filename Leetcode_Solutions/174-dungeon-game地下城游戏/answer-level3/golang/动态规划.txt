逆向思维，从公主的位置，反推到下一个位置时，所需要的血量，比如公主位置是-5，就是说到公主位置之前至少需要准备6滴血，能到公主位置的，只有上和左，左是30，上是1，用6分别减去两个数，如果是负数说明到那个位置之前只需要1滴血（0滴血就死了），如果是正数，说明到那个位置之前需要的血量就是那个数，比如上面的6-1=5，如果一个位置可以从两个位置反推过来，比如示例中1，1点，可以从[1，2]点过来，也可以从[2，1]点过来，上面推算[1，2]点是5，[2，1]点1,取两个值的最小值
```
func calculateMinimumHP(dungeon [][]int) int {
	n := len(dungeon)
	m := len(dungeon[0])
	r := make([][]int, n)
	for i := 0; i < n; i++ {
		r[i] = make([]int, m)
	}
	if dungeon[n-1][m-1] > 0 {
		r[n-1][m-1] = 1
	} else {
		r[n-1][m-1] = 1 - dungeon[n-1][m-1]
	}
	for i := n - 1; i >= 0; i-- {
		for j := m - 1; j >= 0; j-- {
			if i == n-1 && j == m-1 {
				continue
			} else if j == m-1 {
				t := math.Max(1, float64(r[i+1][j]-dungeon[i][j]))
				r[i][j] = int(t)
			} else if i == n-1 {
				t := math.Max(1, float64(r[i][j+1]-dungeon[i][j]))
				r[i][j] = int(t)
			}else {
				t1 := math.Max(1, float64(r[i+1][j]-dungeon[i][j]))
				t2 := math.Max(1, float64(r[i][j+1]-dungeon[i][j]))
				r[i][j] = int(math.Min(float64(t1), float64(t2)))
			}
		}
	}
	return r[0][0]
}
```

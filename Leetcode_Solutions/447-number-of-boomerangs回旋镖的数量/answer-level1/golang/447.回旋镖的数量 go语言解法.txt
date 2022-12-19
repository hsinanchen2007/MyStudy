### 解题思路

建立哈希表，双重循环遍历计算每个点与当前点的距离，并存入哈希表中，若遍历点与当前点的距离已经存在表中，说明当前点和当前遍历点和之前存的那个点这三点可以组成“回旋镖“，因为可以交换顺序，所以乘2，res加上当前遍历点与之前的点能组成几个“回旋镖“，并更新哈希表。

### 代码

```golang
func numberOfBoomerangs(points [][]int) int {
	var res int = 0
	m := make(map[int]int)
	for i := 0;i < len(points);i++ {
		m = make(map[int]int)
		for j := 0;j < len(points);j++ {
			if i == j {
				continue
			}
			distance := (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1])
			if _,ok := m[distance];ok {
				res += m[distance] * 2
				m[distance]++
			}else {
				m[distance] = 1
			}
		}
	}
	return res
}
```
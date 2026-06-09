### 解题思路
有几个注意点：

1. 这里只需要判断距离是否相等，所以不需要真的去计算两点间的实际距离（通常需要开根号），只需要计算距离的平方即可。
2. 因为顺序不同也算一个，所以从一个点出发，每次发现一个距离相等的另一个点，数量就会增加当前距离相等的点的数量的两倍。

针对第二点，举一个例子，输入 **[[0,0],[1,0],[2,0],[1,1]]**，假设当前出发点是 [1,0]：
说明：map 的键表示距离，值表示距离为该键的点的个数
1. 距离 [0,0] 为 1，此时 map[1] 为 0，所以回旋镖数量为 0 + 0 * 2 = 0，并对 map[1] 做加一操作，也即 map[1] = 1
2. 距离 [2,0] 为 1，此时 map[1] 为 1，所以回旋镖数量为 0 + 1 * 2 = 2，并对 map[1] 做加一操作，也即 map[1] = 2
3. 距离 [1,1] 为 1，此时 map[1] 为 2，所以回旋镖数量为 2 + 2 * 2 = 6，并对 map[1] 做加一操作，也即 map[1] = 3

### 代码

```golang
func dist(i []int, j []int) int {
	return (i[0]-j[0])*(i[0]-j[0]) + (i[1]-j[1])*(i[1]-j[1])
}

func numberOfBoomerangs(points [][]int) int {
	num := 0 // number of boomerangs

	for i := range points {
		ht := make(map[int]int, len(points))
		for j := range points {
			if i != j {
				dist := dist(points[i], points[j])
				if cnt, ok := ht[dist]; ok {
					num += cnt * 2
				}
				ht[dist]++
			}
		}
	}

	return num
}

```
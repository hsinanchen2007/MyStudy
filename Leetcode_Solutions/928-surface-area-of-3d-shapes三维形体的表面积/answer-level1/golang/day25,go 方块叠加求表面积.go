### 解题思路
// 先遍历最外层，可以确定y轴的值；再遍历第二层，根据数组值确定x轴的位置，再根据具体的值，确定z轴的高度
// 那么，表面积的计算，可以是所有的方块的表面积（z数量*6）减去重合部分的面积
// 重合一共有3个方向，x,y,z，如果z轴为0，则x和y肯定没有重合部分，如果z不为0，则重合的部分是最小的值*2

### 代码

```golang
func surfaceArea(grid [][]int) int {
	var (
		counts   int
		total    int
		surface  int
		XOverlap int
		YOverlap int
		ZOverlap int
	)

	for i, XAxis := range grid {
		for j, YAxis := range XAxis {
			if YAxis > 0 {
				counts += YAxis
				if i > 0 {
					YOverlap += Min(grid[i-1][j], YAxis) * 2
				}
			}
			if YAxis > 1 {
				ZOverlap += (YAxis - 1) * 2
			}
			if j > 0 && YAxis > 0 {
				XOverlap += Min(XAxis[j-1], YAxis) * 2
			}
		}
	}

	total = counts * 6
	surface = total - XOverlap - YOverlap - ZOverlap

	return surface
}

func Min(i, j int) int {
	if i < j {
		return i
	}
	return j
}
```
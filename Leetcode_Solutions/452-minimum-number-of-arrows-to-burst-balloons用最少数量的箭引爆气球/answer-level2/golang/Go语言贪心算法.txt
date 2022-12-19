### 解题思路
先把points以起点，从小到大进行排序
从第一个气球的结束位置开始向后遍历，如果后面的气球和这个结束位置有交集，则代表可以通过同一箭射破
如果没有交集，则不会被射破，需要下一支箭
如果后面的气球在前面一个气球的范围之内，则箭的位置要前移到后面气球的结束位置

### 代码

```golang
func findMinArrowShots(points [][]int) int {
    if len(points) <= 1 {
        return len(points)
    }
	sort.Slice(points, func(i, j int) bool{
		if points[i][0] < points[j][0] {
			return true
		} else if points[i][0] == points[j][0] && points[i][1] < points[j][1]{
			return true
		}
		return false
	})
	pos := points[0][1]
	num := 1
	for i := 1; i <len(points); i++ {
		if points[i][0] <= pos {
			if points[i][1] < pos {
				pos = points[i][1]
			}
		} else {
			num++
			pos = points[i][1]
		}
	}
	return num
}
```
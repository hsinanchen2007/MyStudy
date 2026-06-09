```
// x,y 轴线

//x2 和x1 比较
//y2 和y1 比较
//min(rec1[x2],rec2[x2]) > max(rec1[x1],rec2[x2]) && min(rec1[y2],rec2[y2]) > max(rec1[y1],rec2[y1])

func isRectangleOverlap(rec1 []int, rec2 []int) bool {
	return (math.Min(float64(rec1[2]), float64(rec2[2])) > math.Max(float64(rec1[0]), float64(rec2[0]))) &&
		(math.Min(float64(rec1[3]), float64(rec2[3])) > math.Max(float64(rec1[1]), float64(rec2[1])))
}
```

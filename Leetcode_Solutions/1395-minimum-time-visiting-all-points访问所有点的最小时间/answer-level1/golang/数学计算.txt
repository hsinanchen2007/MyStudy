### 解题思路
A[x1,y1]，B[x2,y2] 两点间的运行时间可以通过 max(x2-x1,y2-y1) 计算得出，然后计算所有相邻两点间的时间总和就是答案

### 代码

```golang
func minTimeToVisitAllPoints(points [][]int) int {
    var ans int
    for i := 1; i<len(points); i++{
        max := int(math.Abs(float64(points[i][0]-points[i-1][0])))
        t := int(math.Abs(float64(points[i][1]-points[i-1][1])))
        if t>max{
            max = t
        }

        ans += max
    }
    return ans
}
```
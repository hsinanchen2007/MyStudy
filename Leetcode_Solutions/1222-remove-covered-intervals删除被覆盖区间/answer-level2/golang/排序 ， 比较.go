1. [x, y]按照x升序 y降序排列
2. 显然后面所有左边界和它一样的区间都将被删除
3. 若小于 右置位最大值， 一样被删除

```golang
func removeCoveredIntervals(intervals [][]int) int {
    if len(intervals) == 0 || len(intervals[0]) == 0 {
        return 0
    }
    sort.Slice(intervals, func(i, j int) bool { 
        if intervals[i][0] != intervals[j][0] {
            return intervals[i][0] < intervals[j][0]
        }else {
            return intervals[i][1] > intervals[j][1]
        }
    })
    result := 0 
    max := intervals[0][1]
    for i:=1; i < len(intervals); i++ {
        if intervals[i][0] == intervals[i-1][0] {
            result++ 
            continue
        }
        if max < intervals[i][1] {
            max = intervals[i][1]
        } else  {
            result++
        }
    }
    
    return len(intervals) - result
}
// [x, y]按照x升序 y降序排列
// 显然后面所有左边界和它一样的区间都将被删除
// 若小于 右置位最大值， 一样被删除
```
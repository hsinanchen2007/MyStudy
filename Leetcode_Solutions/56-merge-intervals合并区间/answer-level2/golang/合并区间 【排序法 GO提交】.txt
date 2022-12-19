## 思路

- 将输入按起点升序排序
- 从起点开始判断，如果区间可以合并`intervals[i][1] >= intervals[i+1][0]`
- 则合并区间`intervals[i][1] = intervals[i+1][1] > intervals[i][1] ? intervals[i+1][1] : intervals[i][1]` （伪代码，GO不能这样写）
- 删除多余的区间`intervals = append(intervals[:i+1], intervals[i+2:]...)`

## Code

```
func merge(intervals [][]int) [][]int {
    n := len(intervals)
    sort.Slice(intervals, func(a, b int) bool {
        return intervals[a][0] < intervals[b][0]
    })
    
    for i := 0;i < n-1;i++ {
        if intervals[i][1] >= intervals[i+1][0] {
            if intervals[i+1][1] > intervals[i][1] {
                intervals[i][1] = intervals[i+1][1]
            }
            intervals = append(intervals[:i+1], intervals[i+2:]...)
            i--
            n--
        }
    }
    return intervals
}
```

暴力遍历
```
func findRightInterval(intervals [][]int) []int {
    r := []int{}
    for i := 0; i< len(intervals); i++ {
        min, minIdx := 1000000,-1
        for j := 0; j < len(intervals); j++ {
            if i == j {
                continue
            }
            if intervals[i][1] <= intervals[j][0] {
                if intervals[j][0] < min {
                    min = intervals[j][0]
                    minIdx = j
                }
            }
        }
        r = append(r, minIdx)
    }
    return r
}
```

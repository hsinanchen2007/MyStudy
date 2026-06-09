![image.png](https://pic.leetcode-cn.com/2528a0ff8122d00916661ecd64b1fcaf26d80088d4ad43d1563c051875782732-image.png)

```go

// 注意这里只需要计数即可, 不需要返回移除后的数组结果
func eraseOverlapIntervals(intervals [][]int) int {
    n := 0
    if len(intervals) <= 1 {
        return n
    }
    // 排序
    sort.Slice(intervals, func(i, j int) bool { 
        if intervals[i][0] == intervals[j][0] { 
            return intervals[i][1] < intervals[j][1] // 当第0个相同的时候, 比较第二2个
        } 
        return intervals[i][0] < intervals[j][0]
    })

    end := intervals[0][1]

    for i := 1; i < len(intervals); i++ { 
        if intervals[i][0] >= end { 
            end = intervals[i][1]
        } else {
            if intervals[i][1] < end { 
                end = intervals[i][1]
            } 
            n++
        } 

    } 

    return n 
}
```
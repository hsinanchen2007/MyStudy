![image.png](https://pic.leetcode-cn.com/a2bc20858415f90144bc2e713b5c658fbfa3799f67540597e031c53a39ac60dc-image.png)


```go
func merge(intervals [][]int) [][]int { 
    l := len(intervals)
    if l <= 1 {
        return intervals
    }
    sortinterval(intervals) // 按照每个Item第0个元素排序
    i := 0 
    for i < l-1 { 
        A := intervals[i]
        B := intervals[i+1]
        i++ // 指针拨到下一个元素
        if A[1] >= B[0] || A[1] >= B[1] { 
            // 注意这里A[0] , 肯定是最小的
            intervals[i-1] = []int{A[0], max(A[1], B[1])} // 修改第1个元素, 因为上面拨动了指针, 所以这里得-1
            copy(intervals[i:], intervals[i+1:])          // 通过copy移除掉参与合并的元素 , 注意: 这里保留了第i-1前面的所有元素
            intervals = intervals[0 : l-1]                // copy后,最后一个元素是多余的了,移除掉最后一个元素
            i--                                           // 拨回指针到上一个,合并后的新区间, 还需要参与下一次合并计算
            l--                                           // 因为移除掉了一个元素, 所以这里必须减少一个长度
        } 
    } 
    return intervals
}

func sortinterval(intervals [][]int) { 
    // 先排序
    sort.Slice(intervals, func(i, j int) bool { 
        return intervals[i][0] < intervals[j][0]
    })
}

func max(i, j int) int { 
    if i > j { 
        return i 
    } 
    return j 

}
```
### 解题思路
此处撰写解题思路

### 代码

```golang
func cuttingRope(n int) int {
    
    record := make(map[int]int)
    return intBreak(n, record)
}

func intBreak(n int, record map[int]int) int {

    if n == 1 {
        return 1
    }
    if n == 2 {
        return 1
    }
    if _, ok := record[n]; ok {
        return record[n]
    }
    max := -1
    for i:=1; i<n; i++ {
        max = Max(max, i*(n-i), i*intBreak(n-i, record))
    }
    record[n] = max
    return max
}

func Max(i, j, k int) int {

    max := -1
    if i > j {
        max = i
    }else{
        max = j
    }
    if k > max {
        max = k
    }
    return max
}
```
```
func findLucky(arr []int) int {
    list := make([]int, 500)
    res := 0
    for _, m := range arr {
        list[m]++
    }
    for index, m := range list {
        if index == m {
            res = max(res, m)
        }
    }
    
    if res == 0 {
        return -1
    }
    return res
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
```
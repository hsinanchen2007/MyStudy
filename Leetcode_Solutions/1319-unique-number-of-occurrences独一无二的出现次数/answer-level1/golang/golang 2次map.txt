1. 用map统计每个数字出现的次数
2. 用map统计出现次数的次数， 大于1直接返回false
```
func uniqueOccurrences(arr []int) bool {
    m := make(map[int]int)
    for i := 0; i < len(arr); i++ {
        m[arr[i]]++
    }
    times := make(map[int]int)
    for _, v := range m {
        times[v]++
        if times[v] > 1 {
            return false
        }
    }
    return true
}
```

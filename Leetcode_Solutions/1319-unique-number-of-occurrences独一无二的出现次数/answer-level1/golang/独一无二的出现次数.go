### 解题思路
首先使用一个map统计数组中每个数字的出现次数，然后再使用一个map对第一个map对每个数字出现的次数进行计数。

### 代码

```golang
func uniqueOccurrences(arr []int) bool {
    md := make(map[int]int)
    for _, v := range arr {
        md[v]++
    }

    md2 := make(map[int]int)
    for _, v := range md {
        md2[v]++
    }

    for _, v := range md2 {
        if v > 1 {
            return false
        }
    }

    return true
}
```
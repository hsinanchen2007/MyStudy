1. 首先用map统计arr1中的数字
2. 遍历arr2，如果在map中存在，添加到新的数组中，并将对应的map[key]减1
3. 遍历m，把剩余的数按顺序添加
```
func relativeSortArray(arr1 []int, arr2 []int) []int {
    m := make(map[int]int)
    for i := 0; i < len(arr1); i++ {
        m[arr1[i]]++
    }
    ret := make([]int, 0, len(arr1))
    for i := 0; i < len(arr2); i++ {
        for m[arr2[i]] > 0 {
            ret = append(ret, arr2[i])
            m[arr2[i]]--
        }
    }
    for i := 0; i <= 1000; i++ {
        for m[i] > 0 {
            ret = append(ret, i)
            m[i]--
        }
    }
    return ret
}
```

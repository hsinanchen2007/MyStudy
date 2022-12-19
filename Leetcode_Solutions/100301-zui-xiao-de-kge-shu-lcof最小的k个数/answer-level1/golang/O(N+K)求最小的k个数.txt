一般这种容易想到堆，求k大用小顶堆，求k小用大顶堆。
这个题比较特殊，范围有限，可以使用统计排序O(N+K)
```
func getLeastNumbers(arr []int, k int) []int { 
    cnts := make([]int, 10001)
    for i := range(arr) {
        cnts[arr[i]]++
    }
    res := make([]int, 0)
    j := 0
    for i := 0; i < k; i++ {
        for {
            if cnts[j] == 0 {
                j++
            } else {
                res = append(res, j)
                cnts[j]--
                break
            }
        }
    }
    return res
}
```

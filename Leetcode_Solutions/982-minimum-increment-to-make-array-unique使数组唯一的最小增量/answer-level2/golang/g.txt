### 解题思路
此处撰写解题思路

### 代码

```golang
func minIncrementForUnique(A []int) int {
    var arr [80000]int
    res := 0
    for _, m := range A {
        for {
            if arr[m] == 0 {
                arr[m]++
                break
            }else {
                m++
                res++
            }
        }
    }
    return res
}
```
### 解题思路
如果数组中有 40000 个40000，那么数组下边最大到 80000。

思路来源，解决哈希冲突之 开放定址法

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
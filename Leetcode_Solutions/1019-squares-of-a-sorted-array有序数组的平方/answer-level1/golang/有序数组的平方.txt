### 解题思路
so easy

### 代码

```golang
func sortedSquares(A []int) []int {
    var ret []int
    for _, v := range A {
        ret = append(ret, v * v)
    }
    sort.Ints(ret)
    return ret
}
```
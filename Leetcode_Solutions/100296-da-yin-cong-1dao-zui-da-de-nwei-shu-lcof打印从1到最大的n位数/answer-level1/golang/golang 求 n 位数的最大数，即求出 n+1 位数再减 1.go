### 解题思路
求 n 位数的最大数，即求出 n+1 位数再减 1

### 代码

```golang
func printNumbers(n int) []int {
    r := 1
    for i := 0; i < n; i++ {
        r = r*10
        fmt.Println(r)
    }
    var res []int
    for i := 1; i < r; i++ {
        res = append(res, i)
    }
    return res
}
```
比较大小
```
func maximum(a int, b int) int {
    k := a > b
    m := map[bool]int{
        true: 1,
        false: 0,
    }
    return a * m[k] + b * m[!k]
}
```

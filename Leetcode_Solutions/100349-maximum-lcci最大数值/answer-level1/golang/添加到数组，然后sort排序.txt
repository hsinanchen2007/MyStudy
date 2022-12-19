```
func maximum(a int, b int) int {
    slice := make([]int,0,2)
    slice = append(slice,a,b)
    sort.Ints(slice)
    return slice[1]
}
```

```go
func constructArr(a []int) []int {
    if len(a) == 1 || len(a) == 0{
        return a
    }
    left := make([]int, len(a))
    right := make([]int, len(a))

    left[0] = a[0]
    right[len(a)-1] = a[len(a)-1]
    for i := 1; i < len(a); i++ {
        left[i] = left[i-1] * a[i]
    }

    for i := len(a) - 2; i >=0; i-- {
        right[i] = right[i+1] * a[i]
    }

    result := make([]int, len(a))

    result[0] = right[1]
    result[len(a)-1] = left[len(a)-2]
    for i := 1; i < len(a) - 1; i++ {
        result[i] = left[i-1] * right[i+1]
    }
    return result
}
```
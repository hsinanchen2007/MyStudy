```go
func customSortString(S string, T string) string {
    position := make(map[string]int)
    n := len(S)
    for i := 0; i < n; i++ {
        position[string(S[i])] = i
    }
    
    arr := strings.Split(T, "")
    sort.Slice(arr, func(i, j int) bool {
        x := position[arr[i]]
        y := position[arr[j]]
        return x < y
    })

    return strings.Join(arr, "")
}
```

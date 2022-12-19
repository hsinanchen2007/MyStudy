```
func canReach(arr []int, start int) bool {
    if arr[start] == 0 {
        return true
    }
    visited := make(map[int]bool)
    stack := []int{start}
    visited = map[int]bool{start: true}
    start = 0
    for start < len(stack) {
        i := stack[start]
        start++

        idx := i + arr[i]
        if idx >= 0 && idx < len(arr) {
            if !visited[idx] {
                if arr[idx] == 0 {
                    return true
                }
                stack = append(stack, idx)
                visited[idx] = true
            }
        }

        idx = i - arr[i]
        if idx >= 0 && idx < len(arr) {
            if !visited[idx] {
                if arr[idx] == 0 {
                    return true
                }
                stack = append(stack, idx)
                visited[idx] = true
            }
        }
    }

    return false
}
```

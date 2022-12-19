```
func validateBinaryTreeNodes(n int, leftChild []int, rightChild []int) bool {
    for i := 0; i < n; i++ {
        visited := map[int]bool{i: true}
        if vbt(i, leftChild, rightChild, visited) {
            if len(visited) == n {
                return true
            }
        }
    }
    return false
}

func vbt(idx int, leftChild []int, rightChild []int, visited map[int]bool) bool {
    if leftChild[idx] != -1 {
        left := leftChild[idx]
        if visited[left] {
            return false
        }
        visited[left] = true
        if !vbt(left, leftChild, rightChild, visited) {
            return false
        }
    }
    
    if rightChild[idx] != -1 {
        right := rightChild[idx]
        if visited[right] {
            return false
        }
        visited[right] = true
        if !vbt(right, leftChild, rightChild, visited) {
            return false
        }
    }
    return true
}
```

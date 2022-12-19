### 解题思路

### 代码

```golang
func combine(n int, k int) [][]int {
    if k <= 0 || n <= 0 || n < k{
        return nil
    }
    visited := make([]int,0, k)

    // 提前计算组合元素个数：C_n(k) = C_n(n-k)，预分配空间，避免后续slice重新分配空间造成内存碎片
    var total int = 1
    var kmirror int = k
    if n - k < k {
        kmirror = n - k
    }
    for i := 0; i < kmirror; i++ {
        total = total * (n-i)
    }
    result := make([][]int, 0, total)

    return backtrace(n, 1, visited, result, k)
}

func backtrace(n, start int, visited []int, result [][]int, k int) [][]int {
    if len(visited) == k {
        tmp := make([]int, len(visited))
        copy(tmp, visited)
        result = append(result, tmp)
        return result
    }
    last := len(visited)
    visited = append(visited, -1)
    for i := start; i <= n; i++ {
        visited[last] = i
        result = backtrace(n, i+1, visited, result, k)
    }
    return result
}
```
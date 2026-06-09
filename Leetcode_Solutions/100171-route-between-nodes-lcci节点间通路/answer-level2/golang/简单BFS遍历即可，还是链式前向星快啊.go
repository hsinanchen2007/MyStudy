```
func findWhetherExistsPath(n int, graph [][]int, start int, target int) bool {
    vis := make([]bool, n)
    head, next, to := make([]int, n), make([]int, len(graph)+1), make([]int, len(graph)+1)
    cnt := 0
    add := func(a, b int) {
        cnt++
        next[cnt], to[cnt], head[a] = head[a], b, cnt
    }
    for i := range graph {
        add(graph[i][0], graph[i][1])
    }
    q := []int{start}
    for len(q) > 0 {
        t := q[0]
        q = q[1:]
        if vis[t] {
            continue
        }
        vis[t] = true
        for i := head[t]; i != 0; i = next[i] {
            tot := to[i]
            if tot == target {
                return true
            }
            if !vis[tot] {
                q = append(q, tot)
            }
        }
    }
    return false
}
```

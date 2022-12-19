```
type node struct {
    pos int
    state int
    step int
}

func shortestPathLength(graph [][]int) int {
    visited := make([]map[int]struct{}, len(graph))
    queue := list.New()
    success := 0
    for i := 0; i < len(graph); i++ {
        state := 1 << uint(i)
        success |= state
        visited[i] = make(map[int]struct{})
        visited[i][state] = struct{}{}
        queue.PushBack(node{i, state, 0})
    }
    
    for queue.Len() > 0 {
        e := queue.Front()
        now := e.Value.(node)
        if now.state == success {
            return now.step
        }
        queue.Remove(e)
        for _, g := range graph[now.pos] {
            t := now.state | 1 << uint(g)
            if _, ok := visited[g][t]; ok {
                continue
            }
            visited[g][t] = struct{}{}
            queue.PushBack(node{g, t, now.step+1})
        }
    }
    return -1
}
```

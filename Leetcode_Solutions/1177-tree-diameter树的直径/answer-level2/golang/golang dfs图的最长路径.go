第一遍找最深的节点
第二遍计算长度
```
func treeDiameter(edges [][]int) int {
    max := 0
    n := 10000
    grid := make([]map[int]bool, n)
    for i := 0; i < n; i++ {
        grid[i] = make(map[int]bool)
    }
    for i := 0; i < len(edges); i++ {
        grid[edges[i][0]][edges[i][1]] = true
        grid[edges[i][1]][edges[i][0]] = true
    }
    
    root := 0
    dfs(root, grid, map[[2]int]bool{}, 0, &max, &root)
    dfs(root, grid, map[[2]int]bool{}, 0, &max, &root)
    return max
}

func dfs(idx int, grid []map[int]bool, visited map[[2]int]bool, count int, max, ret *int) {
    if count > *max {
        *max = count
        *ret = idx
    }
    for i := range grid[idx] {
        if visited[[2]int{idx, i}] || visited[[2]int{i, idx}] {
            continue
        }
        visited[[2]int{idx, i}] = true
        visited[[2]int{i, idx}] = true
        dfs(i, grid, visited, count + 1, max, ret)
    }
}
```

```

```go
// unoin-find
// doc: https://blog.csdn.net/dm_vincent/article/details/7655764

func removeStones(stones [][]int) int {
    // 并查集初始化
    arr := make([]int, len(stones))
    size := make([]int, len(stones))
    for i := 0; i < len(arr); i++ {
        arr[i] = i
        size[i] = 1
    }
    // 构造并查集
    for i := 0; i < len(stones); i++ {
        for j := i+1; j < len(stones); j++ {
            if stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1] {
                union(&arr, &size, i, j)
            }
        }
    }
    // 找并查集的root节点
    // 每个相连的区域的总结点数减1就是可以消除的石头数
    count := 0
    for idx, rootIdx := range arr {
        if idx == rootIdx && size[idx] > 1 {
            count += size[idx] - 1
        }
    }
    
    return count
}

func union(arr, size *([]int), i, j int) {
    rootI := find(arr, i)
    rootJ := find(arr, j)
    if rootI != rootJ {
        if (*size)[rootI] > (*size)[rootJ] {
            (*arr)[rootJ] = rootI
            (*size)[rootI] += (*size)[rootJ]
        } else {
            (*arr)[rootI] = rootJ
            (*size)[rootJ] += (*size)[rootI]
        }
    }
}

func find(arr *([]int), i int) int {
    for i != (*arr)[i] {
        i = (*arr)[i]
    }
    return i
}
```

```

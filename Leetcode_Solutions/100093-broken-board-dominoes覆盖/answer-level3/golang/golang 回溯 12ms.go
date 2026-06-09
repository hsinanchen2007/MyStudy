因为n， m的数值很小，所以首先想到了回溯算法（个人感觉回溯算法比较无脑）

1. 首先考虑每个点的状态， 不放， 横着放，竖着放。 这部分比较简单，考虑好条件就行
2. 同样的状态尽可能少计算， 这里用到了 used = "0000000000", 判断这个点，这个状态是否已经被计算过了。
```
visited[string(used[idx:])] > 0 // 记录这个点之后的使用情况，如果已经计算过，直接返回。因为前面的点的使用情况不会影响后面的点
```

```
func domino(n int, m int, broken [][]int) int {
    bm := make(map[[2]int]bool)
    for i := 0; i < len(broken); i++ {
        bm[[2]int{broken[i][0], broken[i][1]}] = true
    }
    if len(bm) >= n * m - 1 {
        return 0
    }
    used := make([]byte, n * m)
    for i := 0; i < m * n; i++ {
        used[i] = '0'
    }
    return backtrack(0, n, m, used, bm, map[string]int{})
}

func backtrack(idx int, n, m int, used []byte, bm map[[2]int]bool,visited map[string]int)  int {
    if idx >= n * m {
        return 0
    }
    if visited[string(used[idx:])] > 0 {
        return visited[string(used[idx:])]
    }
    k := -1
    x, y := idx/m, idx%m
    if !bm[[2]int{x, y}] && used[idx] == '0' {
        if x + 1 < n && !bm[[2]int{x+1, y}] && used[idx+m] == '0' {
            used[idx], used[idx+m] = '1', '1'
            k1 := 1 + backtrack(idx + 1, n, m, used, bm, visited)       
            if k1 > k {
                k = k1
            }
            used[idx], used[idx+m] = '0', '0'
        }
        if y + 1 < m && !bm[[2]int{x, y+1}] && used[idx+1] == '0' {
            used[idx], used[idx+1] = '1', '1'
            k1 := 1 + backtrack(idx + 1, n, m, used, bm, visited)
            used[idx], used[idx+1] = '0', '0'
            if k1 > k {
                k = k1
            }
        }
    }
    k1 :=  backtrack(idx + 1, n, m, used, bm, visited)
    if k1 > k {
        k = k1
    }

    visited[string(used[idx:])] = k
    return k
}
```


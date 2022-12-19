

```go
func makeConnected(n int, connections [][]int) int {
    uf := NewUF(n)
    c := 0
    for i:= 0; i < len(connections); i++ {
        isUnion := uf.union(connections[i][0], connections[i][1])
        if false == isUnion {
            c += 1
        }
    }
    count := uf.size() - 1
    if c >= count {
        return count
    }
    return -1
}

type UF struct {
    father []int
    nodeSize []int
    count int
}

func NewUF(n int) *UF {
    uf := UF{
        count: n,
    }
    father := make([]int, n, n)
    nodeSize := make([]int, n, n)
    for i :=0; i< n; i++ {
        father[i] = i
        nodeSize[i] = 1
    }
    uf.father = father
    uf.nodeSize = nodeSize
    return &uf
}

func (uf *UF) find(x int) int {
    for uf.father[x] != x {
        uf.father[x] = uf.father[uf.father[x]]
        x = uf.father[x]
    }
    return x
}

func (uf *UF) union(x, y int) bool {
    fx := uf.find(x)
    fy := uf.find(y)
    if fx == fy {
        return false
    }
    if uf.nodeSize[fx] > uf.nodeSize[fy] {
        uf.father[fy] = fx
        uf.nodeSize[fx] += uf.nodeSize[fy]
    } else {
        uf.father[fx] = fy
        uf.nodeSize[fy] += uf.nodeSize[fx]
    }
    uf.count -= 1
    return true
}

func (uf *UF) size() int {
    return uf.count
}
```

![image.png](https://pic.leetcode-cn.com/f2df32111b1d725a1cd2ffcbe1bc2d97724e78b0bb8d5211f3d231d71ac7b518-image.png)

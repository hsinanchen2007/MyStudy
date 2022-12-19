### 解题思路
此处撰写解题思路

### 代码

```golang

type UnionFind struct {
    count int
    parent []int
}

func (u *UnionFind) Init(count int) {
    u.count = count
    u.parent = make([]int, count)
    for i, _ := range u.parent {
        u.parent[i] = -1
    }
}

func (u *UnionFind) Find(node int) int {
    if u.parent[node] < 0 {
        return node
    }
    result := u.Find(u.parent[node])
    u.parent[node] = result
    return result
}

func (u *UnionFind) Union(node1 int, node2 int) {
    root1 := u.Find(node1)
    root2 := u.Find(node2)
    if root1 == root2 {
        return
    }
    if u.parent[root1] < u.parent[root2] {
        u.parent[root2] = root1
    } else {
        if u.parent[root1] == u.parent[root2] {
            u.parent[root2]--
        }
        u.parent[root1] = root2
    }
    u.count--
}

func findCircleNum(M [][]int) int {
    var uf UnionFind 
    uf.Init(len(M))

    for i, row := range M {
        for j, v := range row {
            if v == 1 {
                uf.Union(i, j)
            }
        }
    }
    return uf.count
}
```
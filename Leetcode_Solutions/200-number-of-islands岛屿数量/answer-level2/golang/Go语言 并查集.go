定义一个struct：
包含三个interface：
union(element1, element2 int) //并查集中的“并”
find(input int) int //并查集中的“查”
getCount() //返回“不相交元素集合”个数
包含两个变量：
count int //记录“不相交元素集合”个数
parent []int //记录每个元素的parent，有相同parent的元素视为在同一个“不相交元素集合”

因为go没有构造函数的概念，所以另外写了一个接口：
NewUnionFind(grid [][]byte) *UnionFind
来实现并查集的初始化

总体思路就比较简单了：
1. 生成并查集，并将所有值为'1'的元素放进相应的“不相交元素集合”中
2. 查看一共有多少个“不相交元素集合”，该值即为题目定义的岛屿的数量

代码如下：
```
type UnionFind struct {
    count int
    parent []int
}

func NewUnionFind(grid [][]byte) *UnionFind {
    ret := new(UnionFind)
    ret.count = 0
    m := len(grid)
    n := len(grid[0])
    parent := make([]int, m * n)
    // 并查集初始化，每一个元素的parent都是它自己，每一个元素单独构成一个不相交元素集合
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if grid[i][j] == '1' {
                parent[i * n + j] = i * n + j
                ret.count++
            }
        }
    }
    ret.parent = parent
    return ret
}

func (uf *UnionFind) union(element1, element2 int) {
    parent1 := uf.find(element1)
    parent2 := uf.find(element2)
    if parent1 != parent2 {
        uf.parent[parent1] = parent2
        uf.count--
    }
}

func (uf *UnionFind) find(input int) int{
    if uf.parent[input] != input {
        uf.parent[input] = uf.find(uf.parent[input])
    }
    return uf.parent[input]
}

func (uf *UnionFind) getCount() int {
    return uf.count
}


func numIslands(grid [][]byte) int {
    if grid == nil || len(grid) == 0 {
        return 0
    }
    row := len(grid)
    col := len(grid[0])
    uf := NewUnionFind(grid)
    for i := 0; i < row; i++ {
        for j := 0; j < col; j++ {
            if grid[i][j] == '1' {
                grid[i][j] = '0'
                cur := i * col + j
                // 只用查找右方和下方的点，左边的点已经在j - 1时处理过了，上边的点已经在i - 1时处理过了
                if i + 1 < row && grid[i + 1][j] == '1' {
                    uf.union(cur, (i + 1) * col + j)
                }
                if j + 1 < col && grid[i][j + 1] == '1' {
                    uf.union(cur, i * col + j + 1)
                }
            }
        }
    }
    return uf.getCount()
}
```
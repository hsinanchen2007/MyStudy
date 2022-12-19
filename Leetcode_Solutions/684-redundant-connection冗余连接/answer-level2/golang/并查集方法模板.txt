
**并查集算法**：由一个一维数组p和两个函数find()、union()构成。数组p[]记录了每个点的父节点编号，节点编号为1...n，函数find查找节点所在树集合根节点，union合并两ke无交集的树。
如畅通工程问题解法，求得最少需要修几条路可实现所有城镇全连通。

**并查集GO模板：**
```
// 查找x节点所在集合的根节点r，并将从x节点开始到r节点中间的节点全部直接挂在r几点下
func find(x int, p []int) {
    r := x
    for p[r] != r {
        r = p[r]
    }
    i := x
    var j int
    for i != r { // 路径压缩，将树高变为2
        j = p[i]
        p[i] = r
        i = j
    }

    return r
}
// 将节点x  y所在集合合并
func union(x, y int, p []int) {
    x_root := find(x, p)
    y_root := find(y, p)
    if x_root != y_root {
        p[x_root] = y_root
    } 
}
```

# 本题实现源码：
```
// 一维数组p[i] = j表示的是第i个节点前驱节点为j, 连通树中根节点k满足p[k]==k
func findRedundantConnection(edges [][]int) []int {
    var res = make([]int, 2)
    var p = make([]int, len(edges)+1)
    for i := 1; i <= len(edges); i++ {
        p[i] = i
    }
    
    for i := 0; i < len(edges); i++ {
        a := find(edges[i][0], p)
        b := find(edges[i][1],p)
        if a == b {
            res = []int{edges[i][0], edges[i][1]}
        } else {
            // 合并
            //p[a] = b
            union(a, b, p)
        }
    }
    return res
}
// 包含了树压缩动作，将每个子集合树变为二级
func find(x int, p []int) int {
    if p[x] != x {
        p[x] = find(p[x], p)
    }
    
    return p[x]
}

// 对两个集合按树根节点（子集的领导节点）合并， x, y为两个集合的任意两个节点
func union(x, y int, p []int) {
    x_root := find(x, p)
    y_root := find(y, p)
    if x_root != y_root {
        p[x_root] = y_root
    } 
}

```
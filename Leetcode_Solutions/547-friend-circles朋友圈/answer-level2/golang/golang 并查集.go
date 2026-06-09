```golang
type UFS struct {
    roots []int
    cnt int
}
func NewUFS(n int) *UFS {
    ufs := &UFS{
            roots: make([]int, n),
            cnt: n,
            }
    for i := range ufs.roots {
        ufs.roots[i] = i
    }
    return ufs
}
func (v *UFS)find(i int) int {
    // if v.roots[i] == i {
    //     return i
    // } 
    root := i
    for v.roots[root] != root {
        root = v.roots[root]
    }
    for v.roots[i] != i {
        tmp := v.roots[i]
        v.roots[i] = root
        i = tmp
        // i, v.roots[i] = v.roots[i], root // 实测提交效率低:(
    }
    return root
}
func (v *UFS)union(i, j int) {
    iRoot, jRoot := v.find(i), v.find(j)
    if iRoot == jRoot {
        return
    }
    v.roots[jRoot] = iRoot
    v.cnt--
}
func findCircleNum(M [][]int) int {
    n := len(M)
    if n < 2 { return n }
    ufs := NewUFS(n)
    for i := range M {
        for j := i+1; j < n; j++ {
            if M[i][j] == 1 {
                ufs.union(i, j)
            }
        }
    }
    return ufs.cnt
}
```
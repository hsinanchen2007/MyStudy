思路：
首先，将n皇后分别放置在不同行， 然后使用DFS去探路确定每一行的皇后所在列的位置，找到则加入re中。

```
func solveNQueens(n int) [][]string {
    if n == 1 {
        return [][]string{{"Q"}}
    }
    if n <= 3 {
        return [][]string{}
    }
    var re [][]int
    shu,pie,na := make(map[int]bool), make(map[int]bool), make(map[int]bool)
    DFS := func(rows []int, n int) {} // 先声明为函数类型，不然无法直接根据带有递归的函数体进行赋值
    DFS = func(rows []int, n int) {
        row := len(rows)
        if row == n {
            aa := make([]int,n)
            copy(aa, rows)
            re = append(re, aa)
            return
        }
        // 不满足则自动返回了，无需结束条件
        for col := 0; col < n; col++ {
            if !shu[col] && !pie[row+col] && !na[row-col] {
                // 做好标记，同一个递归树的子节点不能访问父节点所关联的位置
                shu[col] = true
                pie[row+col] = true
                na[row-col] = true
                DFS(append(rows,col), n)
                // 去除标记，使得同级的递归树节点仍然可以访问这些位置
                shu[col] = false
                pie[row+col] = false
                na[row-col] = false
            }
        }
    }
    DFS([]int{}, n)
    return bQ(re, n)
}
// re:[[1 3 0 2] [2 0 3 1]] 记录的皇后在每一行上的列位置，简化为一维数组
func bQ (re [][]int,n int) (result [][]string) {
    for _,v := range re {
        s := []string{}
        for _,vv := range v{
            str := ""
            for i:=0;i<n;i++ {
                if i == vv {
                    str += "Q"
                }else{
                    str += "."
                }
            }
            s = append(s,str)
        }
        result = append(result,s)
    }
    return
}
```
思路很简单不赘述了，直接上代码。
```
func movingCount(m int, n int, k int) int {
    p := make([][]int, m)
    for i:=0;i<m;i++ {
        p[i] = make([]int, n)
    }
    list := []Index{}
    list = append(list, Index{0,0})
    p[0][0] = 1
    count := 1
    for len(list) > 0 {
        t := list[0]
        list = list[1:]
        // 上
        if canIn(t.row-1, t.col, m, n, k, p) {
            list = append(list, Index{row:t.row-1,col:t.col})
            count++
        }
        
        // 下
        if canIn(t.row+1, t.col, m, n, k, p) {
            list = append(list, Index{row:t.row+1,col:t.col})
            count++
        }
        
        // 左
        if canIn(t.row, t.col-1, m, n, k, p) {
            list = append(list, Index{row:t.row,col:t.col-1})
            count++
        }
        
        // 右
        if canIn(t.row, t.col+1, m, n, k, p) {
            list = append(list, Index{row:t.row,col:t.col+1})
            count++
        }
    }
    return count
}

type Index struct{
    row int
    col int
}

func canIn(row, col, m, n, k int, p [][]int) bool {
    if row<0 || row >= m {
        return false
    }
    if col<0 || col >= n {
        return false
    }
    if p[row][col] == 1 {
        return false
    }
    p[row][col] = 1
    total := bitSum(row) + bitSum(col)
    return total <= k
}

func bitSum(n int) int {
    res := 0
    for n > 0 {
        res += (n % 10)
        n /= 10
    }
    return res
}
```

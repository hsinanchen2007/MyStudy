### 解题思路 ： 经典回溯算法

### 代码

#### 普通解法

```golang
func totalNQueens(n int) int {
    return process (n, 0, make([]int, n))
}

/*
 * n： 总行数
 * i: 当前行
 * record[i]的值: 第i行的棋子放在了第几列
 */
func process(n, i int, record []int) int{
    if i == n {
        return 1
    }
    res := 0
    for k := 0; k < n; k++ {//每一列都去尝试一次
        record[i] = k
        if isValid(i, record) {
            res += process(n, i + 1, record)
        }
    }
    return res
}

func isValid(i int, record []int) bool{
    for j := 0; j < i; j++ {
        if record[i] == record[j] || (abs(record[j] - record[i]) == abs(j - i)) {
            return false
        }
    }
    return true
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}
```

#### 优化
```golang
func totalNQueens(n int) int {
    limit := (1 << n) - 1
    return process(limit, 0, 0, 0)
}

/*
 * limit    : 假如是八皇后，那么后八位全是1，前面的全是0；假如是十皇后，那么后十位全是1，前面的全是0
 * colLimit : 和以前的棋子不能同列的限制
 * leftLimit: 和以前的棋子不能同左对角线的限制
 * rightLimit:和以前的棋子不能同右对角线的限制
 * 以上三个参数为按位或之后的为0的位置就是此行可以选择的位置
 * 然后按位取反再和limit按位与，那么为1的位置就是此行可以选择的位置
*/
func process(limit, colLimit, leftLimit, rightLimit int) int {
    if limit == colLimit {
        return 1
    }

    //此行可以用的位置就是1的位置
    pos := limit & (^(colLimit | leftLimit | rightLimit))
    res := 0
    for pos != 0 {
        mostRightOne := -pos & pos
        pos -= mostRightOne
        res += process(limit,
            colLimit | mostRightOne,
            (leftLimit | mostRightOne) << 1,
            (rightLimit | mostRightOne) >> 1)

    }
    return res
}

```
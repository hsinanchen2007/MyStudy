### 解题思路
如何判断某个格子能否填某个值，可以参考上一问判断数独。
现在是要求填格子。因为数独是可解的，所以很明显，任何一个格子，一定能填上 1-9 中的任意一个数。
所以对于每一个格子，在保证能填入的情况下尝试填入 1-9。当所有空格子都填满了，就说明解开了，如果有空格子没还没填，但是又不能填1-9任何一个数，说明前面步骤填错了，就回退。
所以需要三个map来记录行/列/九宫格已经有了哪些数，一个`blanks`数组记录需要填的空格子。
终止条件是：`blanks`数组的长度为0，说明所有格子都填满了
失败条件是：存在一个格子，无法填入1-9中的任意一个数

### 代码

```golang
func solveSudoku(board [][]byte) {
    row_map, col_map, box_map, blanks := getMaps(board)
    dfs(board, row_map, col_map, box_map, blanks)
}

func dfs(board [][]byte, row_map, col_map, box_map []map[byte]bool, blanks [][2]int) bool {
    // 如果没有空白格子，就说明解开了
    if len(blanks) == 0 {
        return true
    }
    // 获取要填的空白格子
    x, y := blanks[0][0], blanks[0][1]
    // 尝试填入1-9
    for i := 1; i <= 9; i++ {
        n := '0' + byte(i)
        // 如果能够填入这个数
        if canPut(n, x, y, row_map, col_map, box_map) {
            // 填进去
            board[x][y] = '0' + byte(i)
            // 更新映射
            updateMaps(n, x, y, row_map, col_map, box_map, true)
            // 填下一个格子，如果下一个格子完成了，直接返回结果
            if dfs(board, row_map, col_map, box_map, blanks[1:]) {
                return true
            } else {
                // 如果填这个数无法完成，就还原，尝试填入下一个数
                updateMaps(n, x, y, row_map, col_map, box_map, false)
            }
        }
    }
    // 如果九个数都没法填入，恢复原状并返回false
    board[x][y] = '.'
    return false
}

// 初始化行/列/九宫格的映射，并记录空格子
func getMaps(board [][]byte) (a, b, c []map[byte]bool, d [][2]int) {
    col_map := make([]map[byte]bool, 9, 9)  // 列
    row_map := make([]map[byte]bool, 9, 9)  // 行
    box_map := make([]map[byte]bool, 9, 9)  // 九宫格
    blanks := make([][2]int, 0, 81) // 空格子
    for i := 0; i < 9; i++ {
        col_map[i] = make(map[byte]bool)
        row_map[i] = make(map[byte]bool)
        box_map[i] = make(map[byte]bool)
    }
    for i := 0; i < 9; i++ {
        for j := 0; j < 9; j++ {
            if board[i][j] != '.' {
                row_map[i][board[i][j]] = true
                col_map[j][board[i][j]] = true
                box_map[3*(i/3)+j/3][board[i][j]] = true
            } else {
                // 将空白点的索引添加到空白数组
                blanks = append(blanks, [2]int{i, j})
            }
        }
    }
    return row_map, col_map, box_map, blanks
}

// 更新映射
func updateMaps(n byte, x, y int, row_map, col_map, box_map []map[byte]bool, val bool) {
    row_map[x][n] = val
    col_map[y][n] = val
    box_map[3*(x/3)+y/3][n] = val
}

// 判断格子 i, j 能否填入 n
func canPut(n byte, i, j int, row_map, col_map, box_map []map[byte]bool) bool {
    return !row_map[i][n] && !col_map[j][n] && !box_map[3*(i/3)+j/3][n]
}
```
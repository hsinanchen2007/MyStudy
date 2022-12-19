### 解题思路
刷哈希表专题练练手 
用了三个map切片分别存储每行、每列、每个子数独遇到的数字和计数
如果数字计数超过1说明不满足某列或者某行或者某个子数独中不重复的规则直接返回false
否则返回true
### 代码

```golang
func isValidSudoku(board [][]byte) bool {
    maprow := make([]map[int]int, 9)    //行
    mapcol := make([]map[int]int, 9)    //列
    mapbox := make([]map[int]int, 9)    //子数独
    for i := 0; i < 9; i++ {
        maprow[i] = make(map[int]int) 
        mapcol[i] = make(map[int]int)
        mapbox[i] = make(map[int]int)
    }
    for i := 0; i < 9; i++ {
        for j := 0; j < 9; j++ {
            if board[i][j] != '.'{
                temp, _ := strconv.Atoi(string(board[i][j]))  //转换为整型
                maprow[i][temp]++
                mapcol[j][temp]++
                mapbox[(i / 3) * 3 + j / 3][temp]++
                if maprow[i][temp]>1||mapcol[j][temp]>1||mapbox[(i/3)*3+j/3][temp]>1 {
                    return false
                }
                
            }
        }
    }
    return true
}
```
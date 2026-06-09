### 解题思路
此处撰写解题思路

### 代码

```golang
import "fmt"
func findLonelyPixel(picture [][]byte) int {
    row := len(picture)
    col := len(picture[0])
    rowBlack := make([]int, row)
    colBlack := make([]int, col)
    count := 0

    for i := 0; i < row; i++ {
        for j := 0; j < col; j++ {
            if picture[i][j] == 'B' {
                rowBlack[i]++;
                colBlack[j]++;
            }
        }
    }
    for i := 0; i < row; i++ {
        for j := 0; j < col; j++ {
            if picture[i][j] == 'B' && rowBlack[i] == 1 && colBlack[j] == 1 {
                count++
            }
        }
    }
    return count
}
```
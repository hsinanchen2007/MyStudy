### 解题思路
这个的周期性质看一下样本就很容易发现的
顺便我这个还支持中文输入

### 代码

```golang
func convert(s string, numRows int) string {
    if numRows == 1 {
        return s
    }
    rows := make([]string, numRows)
    cycleCharCount := numRows + numRows - 2
    for index, char := range []rune(s) {
        rowIndex := index % cycleCharCount
        if rowIndex >= numRows {
            rowIndex = cycleCharCount - rowIndex
        }
        rows[rowIndex] += string(char)
    }

    ret := ""
    for _, row := range rows {
        ret += row
    }
    return ret
    
}
```
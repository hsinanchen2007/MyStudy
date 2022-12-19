```
func convert(s string, numRows int) string {
    if numRows <= 1 {
        return s
    }

    ss := []rune(s)
    sLen := len(ss)

    newStr := make([]rune, 0)

    // 每个单元：numRows + (numRows - 2)
    unitLen := numRows + numRows - 2
    left := sLen % unitLen
    units := sLen / unitLen
    if left > 0 {
        units++
    }

    // 循环每行
    for i:=0; i<numRows; i++ {
        // 循环每个unit
        for j:=0; j<units; j++ {
            
            nowCellIndex := unitLen * j + i
            if nowCellIndex < sLen {
                newStr = append(newStr, ss[nowCellIndex])
            }

            // 有斜线的数
            if i > 0 && i < numRows - 1 {
                slashCellIndex := unitLen * (j + 1) - i
                if slashCellIndex < sLen {
                    newStr = append(newStr, ss[slashCellIndex])
                }
            }
        }
    }

    return string(newStr)
}
```

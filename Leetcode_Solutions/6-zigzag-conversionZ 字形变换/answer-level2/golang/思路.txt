### 解题思路
执行用时 : 12 ms
构建一个二维数组，其中每个数组为一行内容。

### 代码

```golang
func convert(s string, numRows int) string {
    length := len(s)
    if numRows < 2 {return s}
    one := 2 * numRows -2

    inter := make([][]byte, numRows)
    for i := 0; i < numRows; i++ {
        inter[i] = make([]byte, 0,length/one*2+2)
    }

    for index, data := range []byte(s) {
        loopindex := index % one
        if (loopindex/numRows == 0) {
            inter[loopindex] = append(inter[loopindex], data)
        } else {
            inter[one - loopindex] = append(inter[one - loopindex], data)
        }
    }
    res := make([]byte, 0, length)
    for i := 0; i < numRows; i++ {
        res = append(res, inter[i]...)
    }

    return string(res)

}
```
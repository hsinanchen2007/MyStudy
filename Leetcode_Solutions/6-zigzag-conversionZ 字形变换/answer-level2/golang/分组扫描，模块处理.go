### 解题思路
+ 首先将字符串进行分组，一列+对角无边为一组
- 记Z形行数为n
- 一列为n，对角无边为n-2,则一组元素总数最多为2n-2
+ 既然有规律，利用递归是最简单的,不过递推也不错
+ 递推就是，按组追加行；组内先处理列，再处理对角无边，Over
+ 字符串其实可以预先分配，这样内存消耗也不是个问题

### 代码

```golang
// 首先将字符串进行分组，一列+对角无边为一组
// 记Z形行数为n
// 一列为n，对角无边为n-2,则改组总数为2n-2
// 既然有规律，利用递归是最简单的,不过递推也不错
func convert(s string, numRows int) string {
    if len(s) <= 1||numRows<=1 {
        return s
    }
    lines := make([][]byte, numRows)
    group := 2*numRows - 2
    numGroups := (len(s)+group-1)/group
L:
    for idx:=0; idx < numGroups; idx++{
        start := idx*group
        for i:=0; i< numRows; i++{
            if start + i >= len(s){
                break L
            }
            lines[i] = append(lines[i], s[start+i])
        }
        start = start + numRows
        for i:=0; i< numRows-2; i++{
            if start + i >= len(s){
                break L
            }
            lines[numRows-2-i] = append(lines[numRows-2-i],s[start+i])
        }
    }
    var result []byte
    for _,line:= range lines{
        result = append(result, line...)
    } 
    return string(result)
}
```
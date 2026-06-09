### 代码

```golang
/**
1. 此题的关键是 想到用什么数据结构存储遍历的结果
2. 考虑构建一个 字符串数组作为最后的输出
3. 技巧的话 就是 一个索引指针 加 方向指针 这在很多复杂遍历问题中很常见例如矩阵的多种问题 
4. 何时判断需要变换方向? 在index == 0 或者index 触底时 变换方向
5. index 表示字符串数组的下标
*/
func convert(s string, numRows int) string {
    if len(s) == 0 || numRows == 1{
        return s
    }
    zigZag := make([]string,min(numRows,len(s)))
    down, index, res  := false, 0, ""
    for _, v := range s{
        if index == 0 || index == len(zigZag) -1 {
            down = !down
        }
        zigZag[index] += string(v)
        if down{
            index ++
        }else{
            index --
        }
    }
    for _, zig := range zigZag{
        res += zig
    }
    return res
}
func min(a,b int)int{
    if a < b{
        return a
    }
    return b
}
```

利用GO语言的平行赋值，一次旋转4个元素

```
func rotate(matrix [][]int)  {
    n:=len(matrix)
    a,b:=0,n-1      //左右边界
    c,d:=0,n-1      //上下边界
    
    for {
        for i:=0;i<b-a;i++{
            matrix[c][a+i],matrix[c+i][b],matrix[d][b-i],matrix[d-i][a]=matrix[d-i][a],matrix[c][a+i],matrix[c+i][b],matrix[d][b-i]
        }
        a++
        b--
        c++
        d--
        if a>=b{
            break
        }
    }
}
```

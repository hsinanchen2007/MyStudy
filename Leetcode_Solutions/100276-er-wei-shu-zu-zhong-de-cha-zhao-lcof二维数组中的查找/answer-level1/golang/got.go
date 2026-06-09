### 解题思路
o(m+n),o(1)
这里需要严格判断二维切片和一维切片是不是nil以及长度是不是为0
这里需要注意的是go语言中的for循环的语句不支持逗号表达式
注意点就是不要换行换列搞反了
### 代码

```golang
func findNumberIn2DArray(matrix [][]int, target int) bool{
    if matrix==nil || len(matrix)==0 || matrix[0]==nil || len(matrix[0])==0{
        return false
    }
    rows:=len(matrix)
    colums:=len(matrix[0])
    
    for i,j:=rows-1,0;i>=0 && j<colums;{
        value:=matrix[i][j]
        if value==target{
            return true
        }else if value>target{
            i--
        }else{
           j++
        }
    }
    return false

}

```
```
func spiralOrder(matrix [][]int) []int {
    result:=[]int{}
    m:=len(matrix)
    if m==0{
        return result
    }
    n:=len(matrix[0])
    
    a,b:=0,n-1      //左右边界
    c,d:=0,m-1      //上下边界
    
    size:=m*n
    idx:=0
    Loop:
    for {
        for i:=a;i<=b;i++{
            result=append(result,matrix[c][i])
            idx++
            if idx==size{
                break Loop
            }
        }
        c++         //收缩上边界
        for i:=c;i<=d;i++{
            result=append(result,matrix[i][b])
            idx++
            if idx==size{
                break Loop
            }
        }
        b--         //收缩右边界
        for i:=b;i>=a;i--{
            result=append(result,matrix[d][i])
            idx++
            if idx==size{
                break Loop
            }
        }
        d--         //。。。
        for i:=d;i>=c;i--{
            result=append(result,matrix[i][a])
            idx++
            if idx==size{
                break Loop
            }
        }
        a++         //。。。
    }
    return result    
}
```

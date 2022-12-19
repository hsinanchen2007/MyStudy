### 解题思路
这题关键在于边界值的限制
### 代码

```golang
func spiralOrder(matrix [][]int) []int {
    if len(matrix)==0{
        return []int{}
    }
    var f func(sRow,eRow,sCol,eCol int)
    res:=[]int{}
    f=func(sRow,eRow,sCol,eCol int){
        if sRow>eRow||sCol>eCol{
            return
        }
        i,j:=sRow,sCol
        for j<=eCol{
            res=append(res,matrix[i][j])
            j++
        }
        j--
        i++
        for i<=eRow{
            res=append(res,matrix[i][j])
            i++
        }
        i--
        j--
        for j>=sCol&&i>sRow{
            res=append(res,matrix[i][j])
            j--
        }
        j++
        i--
        for i>sRow&&j<eCol{
            res=append(res,matrix[i][j])    
            i--   
        }
        f(sRow+1,eRow-1,sCol+1,eCol-1)
    }
    f(0,len(matrix)-1,0,len(matrix[0])-1)
    return res
}
```
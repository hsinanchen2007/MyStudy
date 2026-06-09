### 代码

```golang
func maxValue(grid [][]int) int {
    var f func(i,j int)int
    note:=make([]int,len(grid)*len(grid[0]))
    f=func(i,j int)int{ 
        if i==0&&j==0{
            return grid[0][0]
        }else if note[i*len(grid[0])+j]!=0{
            return note[i*len(grid[0])+j]
        }else if i==0{
            return grid[i][j]+f(i,j-1)
        }else if j==0{
            return grid[i][j]+f(i-1,j)
        }
        a,b:=f(i-1,j),f(i,j-1)
        if a>b{
            res:=a+grid[i][j]
            note[i*len(grid[0])+j]=res
            return res
        }else{
            res:=b+grid[i][j]
            note[i*len(grid[0])+j]=res
            return res
        }
    }
    return f(len(grid)-1,len(grid[0])-1)
}
```
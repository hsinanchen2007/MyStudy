### 代码

```golang
func generateMatrix(n int) [][]int {
    help:=[][]int{{0,1},{1,0},{0,-1},{-1,0}}
    res:=make([][]int,n)
    for i:=0;i<n;i++{
        res[i]=make([]int,n)
    }
    index,x,y:=0,0,0
    for i:=1;i<=n*n;i++{
        res[x][y]=i
        x+=help[index][0]
        y+=help[index][1]

        if x<0||y<0||y>=n||x>=n||res[x][y]!=0{
            x-=help[index][0]
            y-=help[index][1]
            index=(index+1)%4
            x+=help[index][0]
            y+=help[index][1]
        }
    }
    return res
}
```
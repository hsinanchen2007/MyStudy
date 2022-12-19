### 解题思路
此处撰写解题思路

### 代码

```golang
func surfaceArea(grid [][]int) int {
    if grid==nil || len(grid)==0{
        return 0
    }
    //四个方向
    dx:=[]int{-1,0,1,0}
    dy:=[]int{0,-1,0,1}
    sum:=0
    for i:=0;i<len(grid);i++{
        for j:=0;j<len(grid[0]);j++{
            if grid[i][j]!=0{
                //对于叠起来的立方体，表面积可以写为：
                //最上面和最下面的面积都是5，中间为4，所以sum=(i-2)*4+10
                sum+=(grid[i][j]-2)*4+10
            }
            //将互相遮住的减去，能够遮住的一定是该点的水平和垂直方向
            for k:=0;k<4;k++{
                newi,newj:=i+dx[k],j+dy[k]
                if newi>=0 && newi<len(grid) && newj>=0 && newj<len(grid[0]){
                    //将被遮住的位置的面积去掉，被遮住的肯定是
                    //grid[i][j],grid[newi][newj]的最小值
                    sum-=min(grid[i][j],grid[newi][newj])
                }
            }
        }
    }
    return sum
}

func min(a,b int) int {
    if a<b {
        return a
    }
    return b
}
```
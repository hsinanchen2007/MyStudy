### 解题思路
从上至下，从左至右，遍历单元格，则只需要减去单元格上方及左方的方块重叠面积，最终得出答案；

### 代码

```golang
func surfaceArea(grid [][]int) int {
    h := len(grid)
    if( h == 0){
        return 0
    }

    w := len(grid[0])
    if( w == 0){
        return 0
    }


    m := func(x,y int) int{
        min := x
        if(y < x){
            min = y
        }
        return min
    }
    ret := 0
    for i:=0;i<h;i++{
        for j:=0;j<w;j++{
            if( grid[i][j] > 0){
                ret += 2    //top and bottom

                cur := grid[i][j]
                ret += 4 * cur   //common

                // - up
                if( i != 0 ){
                    cp := grid[i-1][j]
                    min := m(cur,cp)
                    ret -= min*2
                }

                // - left
                if( j != 0){
                    cp := grid[i][j-1]
                    min := m(cur,cp)
                    ret -= min*2
                }
            }
        }
    }

    return ret
}
```
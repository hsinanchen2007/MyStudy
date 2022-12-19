### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/73b25d716bf4455e1ea07d647b43490be3088834e25dd6d1938c5ac5ac367598-image.png)

### 代码

```golang
//看完题解才理解题意

//首先理解题意，NN的二维数组中的每个值代表着这个位置上有几个立方体，例如，[[2]]代表1X1的表格中上坐标(0,0)的位置上有2个立方体，[[1,2],[3,4]]则代表2X2的表格中坐标(0,0)(0,1)(1,0)(1,1)上分别有1,2,3,4个立方体，以此类推。

//注意，只算有立方体的位置连接成的最终形体的表面积

//继续示例2
//一共表面积 10*6
//侧面相连的 2+2+3
//垂直方面相连的面 1+2+3
//有相连的面  表面积-2
//10*6-7*2-6*2=34



func surfaceArea(grid [][]int) int {
    var node int 
var v int //垂直方向相连的面
var c int //侧面相连的面
  for i:=0;i<len(grid);i++ {
      for j:=0;j<len(grid[i]);j++{
        if grid[i][j]==0 {
            continue
        }else {
          node +=grid[i][j]
          v +=grid[i][j]-1
          if i ==0 && j==0 {
            continue
          }
          if i==0 {
               c += min(grid[i][j],grid[i][j-1])
               continue
          }
          if j==0 {
               c += min(grid[i][j],grid[i-1][j]) 
               continue
          }

           c += min(grid[i][j],grid[i-1][j])  + min(grid[i][j],grid[i][j-1])
        
        }

      }
  }
  return node*6-c*2-v*2
}

func min(x,y int) int {
    if x<y {
        return x
    }else {
        return y
    }
}
```
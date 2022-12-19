### 解题思路
分析：要最短路径，则只可能往下走或者往右走，如果往上走或者往左走，则一定有比它更短的路径。
根据上面的最短原则，一个网格中的点x，只受x上面的点y和x左边的点z的影响，我们选择y和z中更短的路径。

一个直观的想法是，要到终点最短，则选择到终点上面的点的路径和到终点左边的点的路径中更短的一条路径。
比较这2点中那个路径最短，显然需要比较这2点各自的上面的点和左边的点的路径长度，继续推，会有更多的比较出现。显然这是从上而下的分析步骤。

利用动态规划，我们需要从下而上解决问题，从左往右，从上往下遍历每个点，计算这个点到下面的点或右边的点的最短路径，比较其他点到这个点的下面的点或右边的点的最短距离，保留更短的路径即可。

我们用一个mxn的二维数组保留这个比较过程，返回这个二维数组右下的元素大小即可。

进一步优化：不需要用额外的dp 数组，而是在原数组上存储，这样就不需要额外的存储空间。递推公式如下：
 grid(i,j)=grid(i,j)+min(grid(i+1,j),grid(i,j+1))
### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        //行数m
        int num_line = grid.length;
        //列数n
        int num_row = grid[0].length;
        //建立result网格
        int[][] result = new int[num_line][num_row];
        //初始化
        for (int i =0;i<num_line;i++){
            for (int j = 0 ;j<num_row;j++){
                result[i][j] = Integer.MAX_VALUE;
            }
        }
        //左上点无需计算
        result[0][0] = grid[0][0];
        for (int line = 0 ; line<num_line;line++){
            for (int row = 0;row<num_row;row++){
                //如果不是在网格的最右一列，则比较result网格中右边一列的值和result网格中该位置的值+到右边一列的值（grid中右边一列的值）
                if (row<num_row-1){
                    if ((result[line][row]+grid[line][row+1])<result[line][row+1]){
                        result[line][row+1] = result[line][row]+grid[line][row+1];
                    }
                }
                //如果不是在网格的最下一行，则比较result网格中下边一行的值和result网格中该位置的值+到下边一行的值（grid中下边一行的值）
                if (line<num_line-1){
                    if ((result[line][row]+grid[line+1][row])<result[line+1][row]){
                        result[line+1][row] = result[line][row]+grid[line+1][row];
                    }
                }
            }
        }

        return result[num_line-1][num_row-1];
    }
}
```
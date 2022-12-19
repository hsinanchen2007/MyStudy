### 解题思路
我用的就是笨方法，从（0，0）处开始往右爬，爬到底爬不过去就掉头，往下，再往左，再往上，依次循环。爬不过去有两层意思：
1、范围越界了
2、该位置被访问过了
所以必须申请一个同样大小的数组来储存访问状态，最后运行效果不尽人意，但我觉得还是比较好理解的一种思路。

### 代码

```java
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        int row = matrix.length;
        if(row==0){
            return new int[0];
        }
        int col = matrix[0].length;
        if(col==0){
            return new int[0];
        }
        boolean[][] visited = new boolean[row][col]; 
        int len = row * col;
        int[] res = new int[len];
        //最终结果数组的索引
        int index  = 0;
        int i = 0 , j = 0;
        //右 下 左 右
        int[] di = {0,1,0,-1};
        int[] dj = {1,0,-1,0};
        //控制当前走向，一直走到头走不动再换方向
        int cycle = 0;
        while(isSafe(i,j,row,col,visited) && index < len){
            //当前节点已经访问过
            visited[i][j] = true;
            res[index++] = matrix[i][j];
            i = i + di[cycle % 4];
            j = j + dj[cycle % 4];

            if(!isSafe(i,j,row,col,visited)){
                i = i - di[cycle % 4];
                j = j - dj[cycle % 4];
                cycle++;
                i = i + di[cycle % 4];
                j = j + dj[cycle % 4];
            }
        }
        return res;
    }

    //判断当前i,j这个位置是否范围有效且没有被访问过
    private boolean isSafe(int i, int j, int row, int col, boolean[][] visited){
        return i>=0 && i < row && j >= 0 && j < col && !visited[i][j];
    }
}
```
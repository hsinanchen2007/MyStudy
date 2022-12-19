相比于62题，这道题是花了半小时钻研而来，纯手写打造... ...

我们需要考虑:

1. 第一行，第一列，如果有1(路障)，则从此到尾都要置0，因为到达不了!
2. 每个单元格都要遍历一次，那么遇到障碍物1，可以置为0，这样上加左的和是当前位置的路径数量，相当于只加左或者只加上，保证不出错！
```
// java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if(obstacleGrid.length == 0 || obstacleGrid[0][0] == 1) return 0;
        // a[i][j]  当前第i,j坐标的路径数目
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        boolean z = false;
        for(int i = 0; i < n; i++){
            if(obstacleGrid[0][i] == 1){
                obstacleGrid[0][i] = 0;
                z = true;
            }
            else if(!z) obstacleGrid[0][i] = 1;
            else if(z) obstacleGrid[0][i] = 0;
        }   
        z = false;
        for(int i = 1; i < m; i++){
            if(obstacleGrid[i][0] == 1){
                obstacleGrid[i][0] = 0;
                z = true;
            }
            else if(!z) obstacleGrid[i][0] = 1;
            else if(z) obstacleGrid[i][0] = 0;
        }
        // 可以看到当前的位置上的数组值
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         System.out.println("obstacleGrid["+i+"]["+j+"]:"+obstacleGrid[i][j]);
        //     }
        // }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    obstacleGrid[i][j] = 0;
                    continue;
                }
                obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                // System.out.println("obstacleGrid["+i+"]["+j+"]:"+obstacleGrid[i][j]);
            }
        }
        return obstacleGrid[m-1][n-1];
    }
}
```
**执行用时 :1 ms, 在所有 java 提交中击败了91.43%的用户**

**内存消耗 :39.2 MB, 在所有 java 提交中击败了5.08%的用户**
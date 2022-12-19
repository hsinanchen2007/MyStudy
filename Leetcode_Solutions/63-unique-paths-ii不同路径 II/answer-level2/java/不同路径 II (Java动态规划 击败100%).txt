# 动态规划
由于机器人运动方式是单一向左或者向右，加上障碍之后，我们可以先**初始化第一行和第一列**:
1.如果遇到'0',则在原来数组上将它置为1——只有一条路径可达。
2.如果遇到'1',表示遇到障碍物，将其初始化为0，之后向下或者向左全部初始化为0，表示无法到达。
然后从数组的第二行第二列开始规则如下:
1.arr[i][j]如果不是障碍物，到达这个方框的方法数为**arr[i-1]+arr[j-1]**。
2.arr[i][j]如果是障碍物_'1'，则将这个位置置'0'，表示无法到达。
代码如下:
```
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        obstacleGrid[0][0] = 1;
        int row = obstacleGrid.length;
        int col = obstacleGrid[0].length;
        //原有基础上 初始化列
        for(int i=1;i<row;i++){
            if(obstacleGrid[i][0] == 0){
                obstacleGrid[i][0] = 1;
            }else{
                for(int j=i;j<row;j++){
                    obstacleGrid[j][0] = 0;
                }
                break;
            }
        }
      //原有基础上 初始化行
        for(int i=1;i<col;i++){
            if(obstacleGrid[0][i] == 0){
                obstacleGrid[0][i] = 1;
            }else{
                for(int j=i;j<col;j++){
                    obstacleGrid[0][j] = 0;
                }
                break;
            }
        }
        //填写数组
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(obstacleGrid[i][j] == 1){
                    obstacleGrid[i][j] = 0;
                }else{
                    obstacleGrid[i][j] = obstacleGrid[i][j-1]+obstacleGrid[i-1][j];
                }
            }
        }
        return obstacleGrid[row-1][col-1];
    }
}
```
本人菜鸟,如有错误,感谢指正！

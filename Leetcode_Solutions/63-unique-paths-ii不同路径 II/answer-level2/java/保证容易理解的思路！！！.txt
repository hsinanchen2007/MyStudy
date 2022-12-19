### 解题思路
跟上一道题目类似，只是在初始化边界值（第一行和第一列）的时候需要主要如果遇到了阻碍，就不能往下执行了，因为那些位置不能到达，所以不能初始化为1，就只能为0。
然后继续利用上题的关系 matric[i][j] = matric[i-1][j] + matric[i][j-1] 进行推算，只不过需要加入一个判断，需要判断我们计算的下一个位置时候存在阻碍。

弱鸡继续前进solve DP》》》

### 代码

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int row = obstacleGrid.length; // 行
        int col = obstacleGrid[0].length; //列
        int[][] matric = new int[row][col];
        // 初始化matric
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                matric[i][j] = 0;
            }
        }
        for(int i=0;i<col;i++){
            if(obstacleGrid[0][i]==1){
                break;
            }else{
                matric[0][i] = 1;
            }
        }
        for(int j=0;j<row;j++){
            if(obstacleGrid[j][0]==1){
                break;
            }else{
                matric[j][0] = 1;
            }
        }
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(obstacleGrid[i][j]==1){
                    continue;
                }else {
                    matric[i][j] = matric[i-1][j] + matric[i][j-1];
                }
            }
        }
        return matric[row-1][col-1];
    }
}
```
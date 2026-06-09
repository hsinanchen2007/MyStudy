现在看来做题的时候也要有Dynamic Programming的精神。
做一道题之前先画个图然后考虑一下有哪些情况存在。
像这道题就是的：先假设你是机器人，然后考虑情况：
1.如果在最上面一排有任何一个被堵上了，你这一排下面就不要走了。
对列同理。
2.剩下的用二维数组构建一个地图就好了。
代码：

```
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int[][] arr = new int[obstacleGrid.length][obstacleGrid[0].length];
        for(int i = 0; i < obstacleGrid.length; i++){if(obstacleGrid[i][0]>0)break; arr[i][0] = 1;}
        for(int j = 0; j < obstacleGrid[0].length;j++) {if(obstacleGrid[0][j]>0)break;arr[0][j] = 1;}
        for(int i = 1; i < obstacleGrid.length; i++){
            for(int j = 1; j < obstacleGrid[0].length;j++){
                if(obstacleGrid[i][j]!=1){
                    arr[i][j] = arr[i-1][j] + arr[i][j-1];
                } 
            }
        }
        return arr[obstacleGrid.length-1][obstacleGrid[0].length-1];
    }
}
```

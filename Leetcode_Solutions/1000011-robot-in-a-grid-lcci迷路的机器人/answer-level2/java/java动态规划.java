### 解题思路
看评论区老哥逆推路径，实现了下

### 代码

```java
class Solution {
    public List<List<Integer>> pathWithObstacles(int[][] obstacleGrid) {
            //动态规划
        int[][] dp = new int[obstacleGrid.length][obstacleGrid[0].length];
        boolean flag = true;
        //列
        for(int i = 0;i < obstacleGrid.length;i++){
            if(obstacleGrid[i][0] == 0 && flag){
                dp[i][0] = 1;
            }else{
                flag = false;
                dp[i][0] = 0;
            }
        }
        flag = true;
        //行
        for(int i = 0;i < obstacleGrid[0].length;i++){
            if(obstacleGrid[0][i] == 0 && flag){
                dp[0][i] = 1;
            }else{
                flag = false;
                dp[0][i] = 0;
            }
        }
        for(int i = 1;i < obstacleGrid.length;i++){
            for(int j = 1;j < obstacleGrid[0].length;j++){
                if(obstacleGrid[i][j] == 0){
                    dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]);
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        List<List<Integer>> res = new ArrayList<>();
        int r = dp.length-1;
        int c = dp[0].length-1;
        if(dp[r][c] == 0) return res;
         while (r != 0 || c != 0) {
           res.add(0,Arrays.asList(r,c));
            int up = 0;
            if (r > 0)
                up = dp[r - 1][c];

            int left = 0;
            if (c > 0)
                left = dp[r][c - 1];

            if (up >= left)
                r--;
            else
                c--;
        }
        res.add(0,Arrays.asList(r,c));
        return res;

    }
}
```
执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
53.33%
的用户
内存消耗 :
35.7 MB
, 在所有 Java 提交中击败了
41.44%
的用户
```
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        if(m==0)return 0;
        int n = obstacleGrid[0].length;
        int[][] res = new int[m][n];
        
        
        for(int i=0; i<m; i++){
             for(int j=0; j<n; j++){
                if(i==0&&j==0&&obstacleGrid[0][0]!=1){
                    res[0][0]=1;
                }else if(obstacleGrid[i][j]==1){
                    res[i][j]=0;
                }else{
                    res[i][j]=get(res,i,j-1)+get(res,i-1,j);
                }
                // System.out.println(i+"-"+j+"-"+res[i][j]);
             }
        }
        return res[m-1][n-1];
    }
    private int get(int[][] in, int i, int j){
        if(i==-1||j==-1)return 0;
        
        return in[i][j];
    }
}
```

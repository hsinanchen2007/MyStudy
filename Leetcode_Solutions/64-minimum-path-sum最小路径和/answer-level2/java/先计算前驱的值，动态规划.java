执行结果：
通过
显示详情
执行用时 :
5 ms
, 在所有 Java 提交中击败了
76.22%
的用户
内存消耗 :
40.8 MB
, 在所有 Java 提交中击败了
75.09%
的用户
```
class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        if(m==0)return 0;
        int n = grid[0].length;
        if(m==1&&n==1)return grid[0][0];
        int[][] res = new int[m+1][n+1];
        for(int j=0; j<=n; j++){
            res[0][j]=Integer.MAX_VALUE;
        }
        for(int j=0; j<=m; j++){
            res[j][0]=Integer.MAX_VALUE;
        }
        res[1][1]=grid[0][0];
        for(int i=1; i<=m; i++){
            int k=1;
            if(i==1)k=2;
            for(int j=k; j<=n; j++){
               res[i][j]=Math.min(res[i-1][j],res[i][j-1])+grid[i-1][j-1]; 
                //System.out.println(res[i][j]);
                
            }
        }
        return res[m][n];
        
    }
}
```

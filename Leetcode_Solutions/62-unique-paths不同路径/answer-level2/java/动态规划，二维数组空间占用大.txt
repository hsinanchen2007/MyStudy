执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 Java 提交中击败了
95.69%
的用户
内存消耗 :
33 MB
, 在所有 Java 提交中击败了
14.06%
的用户
```
class Solution {
    public int uniquePaths(int m, int n) {
        if(m==0&&n==0)return 0;
        if(m==0||n==0)return 0;
        if(m==1||n==1)return 1;
        int[][] res = new int[m][n];
        for(int i=0; i<m; i++){
            res[i][0]=1;
        }
        for(int i=0; i<n; i++){
            res[0][i]=1;
        }
        for(int i=1; i<m; i++){
           for(int j=1; j<n; j++){
                res[i][j]=res[i-1][j]+res[i][j-1];
           } 
        }
        return res[m-1][n-1];
    }
}
```

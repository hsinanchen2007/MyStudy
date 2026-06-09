```
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] pathrecord = new int[m][n];
        
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i==0||j==0){
                    pathrecord [i][j]=1;
                }else{
                    pathrecord[i][j]=pathrecord[i][j-1]+pathrecord[i-1][j];
                }
                
            }
        }
        return pathrecord[m-1][n-1];
    }
}
```

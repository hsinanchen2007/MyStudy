```
class Solution {
    private int[][] mat;
    private int n;
    private int m;
    private int res = Integer.MAX_VALUE;
    public int minFlips(int[][] mat) {
        this.mat = mat;
        this.n = mat.length;
        this.m = mat[0].length;
        dfs(0,0,0);
        return res == Integer.MAX_VALUE?-1:res;
    }
    private void dfs(int i,int j,int step){
        if (pre(i,j)){
            if (i==n){
                if (mat[n-1][m-1]==0){
                    res = Math.min(res,step);
                    return;
                }else return;
            }
        }else return;
        int next_i = 0;
        int next_j = 0;
        if (j==m-1){
            next_i = 1;
            next_j = 1-m;
        }else
            next_j = 1;
        change(i,j);
        dfs(i+next_i,j+next_j,step+1);
        change(i,j);
        dfs(i+next_i,j+next_j,step);
    }
    private void change(int i,int j){
        if (i==n)
            return;
        mat[i][j] ^= 1;
        if (i>0)
            mat[i-1][j] ^= 1;
        if (i<n-1)
            mat[i+1][j] ^= 1;
        if (j>0)
            mat[i][j-1] ^= 1;
        if (j<m-1)
            mat[i][j+1] ^= 1;
    }
    private boolean pre(int i,int j){
        if (i==0 && j==0)
            return true;
        if (j>0)
            j-=1;
        else{
            i-=1;
            j=m-1;
        }
        if (i>0 && j>0 && mat[i-1][j-1]==1)
            return false;
        if(i==n-1 && j>0 && mat[i][j-1]==1)
            return false;
        if(j==m-1 && i>0 && mat[i-1][j]==1)
            return false;
        return true;
    }
}
```

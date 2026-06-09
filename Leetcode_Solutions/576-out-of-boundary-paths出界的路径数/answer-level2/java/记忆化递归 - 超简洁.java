```
class Solution {
    private Integer[][][] memo;
    private int[] offsets = new int[] {0,1,0,-1,0};
    public int findPaths(int m, int n, int N, int i, int j) {
        memo = new Integer[m][n][N+1];
        return count(m, n, i, j, N);
    }
    
    private int count(int m, int n, int i, int j, int N) {
        if(N < 0) return 0;
        if(i<0||i==m||j<0||j==n) return 1;
        if(memo[i][j][N]!=null) return memo[i][j][N];
        int ans = 0;
        for(int k=0;k<4;k++) {
            ans = (int)(((long)ans + count(m, n, i + offsets[k], j + offsets[k+1], N - 1)) % 1000000007);
        }
        return memo[i][j][N] = ans;
    }
}
```

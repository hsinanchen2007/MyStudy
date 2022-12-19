是个比较基础的dp题。dp[i][j][k]的含义是走到坐标ij时并且步数用了k步后，所有的路线数。k的变化范围设置成1~N-1，转移方程是dp[i][j][step] += dp[nowm][nown][step-1];
nowm，nown是上下左右四个方向的坐标。最后返回的结果就是最上面一行，最下面一行，最左一列，最右一列的第0步到N-1步的路线数的累加，因为再多走一步就可以出去了，
并且走的步数<=N。
```
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        long long M = pow(10,9)+7;
        int dp[51][51][51] = {0};
        dp[i][j][0] = 1;
        int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
        for(int step = 1 ; step <= N-1 ; step++){
            for(int i = 0 ; i < m ; i++){
                for(int j = 0 ; j < n ; j++){
                    for(int k = 0 ; k < 4; k++){
                        int nowm = i+dir[k][0];
                        int nown = j+dir[k][1];
                        if(nowm < m && nowm >= 0 && nown < n && nown>=0){
                            dp[i][j][step] += dp[nowm][nown][step-1];
                            dp[i][j][step]%=M;
                        }
                    }
                }
            }
        }
        long long ans =0 ;
        for(int i = 0 ; i < m ; i++){
            for(int k = 0 ; k <= N-1 ; k++){
                ans+=dp[i][0][k];
                ans+=dp[i][n-1][k];
                ans%=M;
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int k = 0 ; k <= N-1 ; k++){
                ans+= dp[0][i][k];
                ans+=dp[m-1][i][k];
                ans%=M;
            }
        }
        return ans;
    }
};
```

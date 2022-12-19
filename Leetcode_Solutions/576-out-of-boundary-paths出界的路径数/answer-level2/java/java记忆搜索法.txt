![image.png](https://pic.leetcode-cn.com/205713190a74303046e2d435e1e25bcd463cdcef9e180df0494aac266944c1af-image.png)

//需要三维的缓存空间
class Solution {
    final int mod = 1000000007;
    public final int findPaths(int m, int n, int N, int i, int j) {
        int[][][] cache=new int[m][n][N+1];
        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                for(int z=0;z<N+1;z++){
                    cache[x][y][z]=-1;
                }
            }
        }
        int re=findPaths1(m,n,N,i,j,cache);
        return re;
    }
    
    public final int findPaths1(int m,int n,int N,int i,int j,int[][][] cache){
        if(N<0){
            return 0;       
        }
        
        if(i==m||j==n||i<0||j<0){
            return 1;
        }
        
        if(cache[i][j][N]==-1){
            cache[i][j][N]=0;
            cache[i][j][N]+=findPaths1(m,n,N-1,i-1,j,cache);
            cache[i][j][N]%=mod;
            cache[i][j][N]+=findPaths1(m,n,N-1,i+1,j,cache);
            cache[i][j][N]%=mod;
            cache[i][j][N]+=findPaths1(m,n,N-1,i,j-1,cache);
            cache[i][j][N]%=mod;
            cache[i][j][N]+=findPaths1(m,n,N-1,i,j+1,cache);
            cache[i][j][N]%=mod;

        }
        return cache[i][j][N];
    }
}
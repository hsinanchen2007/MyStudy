### 解题思路
代码是看的别人的 写写自己的想法吧 
这种方法也是暴力求解 利用三维数组
将每一个网格置为-1 遍历到这个网格时将其置为0
一开始我也是打算用二维数组这么做 后面发现足球可以折返跑 回到经常遍历过的网格
三维数组巧妙的解决了这个问题

### 代码

```java
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
    // 所有步数已经走完 还是没有到达边界 返回0
    if(N<0){
        return 0;       
    }
    //当符合条件时 说明球已经来到了边界 路径数加一
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


```
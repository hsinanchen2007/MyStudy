### 解题思路
为了这两个解法，本菜鸡也是写了好久；
**方法一：DFS+记忆化搜索   **  
一开始直接写DFS，结果超时，毕竟结果的数值这么大，没有想到更好的剪枝策略；记忆化搜索有点动态规划的思想，将之前的结果保存起来便于计算以减少耗时，这里是用一个HashMap记录，而HashMap的key为int[]又比较麻烦，值相同引用不同，本菜鸡就将i,j,N转换成字符串；
**方法二：动态规划   **
定义在第k步时的dp[i][j]是从位置[i,j]走出界的路径数，因此每一步都会有一个dp矩阵，其实可以减少为两个矩阵，第k+1步中，dp[i][j]为上下左右四个方向的路径数的和，如果[i,j]的下一步出界，则路径数加1；

### 代码
DFS+记忆化搜索
```java
class Solution {
    Map<String,Integer> map = new HashMap<>();
    public int findPaths(int m, int n, int N, int i, int j) {
        //map保存的是从[i,j]走到[x,y]后剩余步数为N再走到边界的路径数
        return dfs(m,n,N,i,j);
    }
    public int dfs(int m,int n,int N,int i,int j){
        if(N<0) return 0;
        if(N<i+1 && N<j+1 && N<m-i && N<n-j) return 0;
        if(i<0 || i>=m || j<0 || j>=n){
            return 1;
        }
        if(map.containsKey(i+","+j+","+N)){
            return map.get(i+","+j+","+N);
        }
        int count = 0;
        count = (count+dfs(m,n,N-1,i+1,j))%1000000007;
        count = (count+dfs(m,n,N-1,i-1,j))%1000000007;
        count = (count+dfs(m,n,N-1,i,j+1))%1000000007;
        count = (count+dfs(m,n,N-1,i,j-1))%1000000007;
        map.put(i+","+j+","+N,count);
        return count;
    }
}
```
动态规划：   
```java
class Solution {
    public int findPaths(int m, int n, int N, int i, int j) {
        if(N==0) return 0;
        int mod = 1000000007;
        int[][] direct = {{1,0},{-1,0},{0,1},{0,-1}};
        int[][] dp = new int[m][n];
        for(int k=0;k<N;k++){
            int[][] tmp = new int[m][n];
            for(int x=0;x<m;x++){
                for(int y=0;y<n;y++){
                    for(int[] d: direct){
                        if(x+d[0]<0 || x+d[0]>=m || y+d[1]<0 || y+d[1]>=n){
                            tmp[x][y]++;
                        }else{
                            tmp[x][y] = (tmp[x][y]+dp[x+d[0]][y+d[1]])%mod;
                        }
                    }
                }
            }
            dp = tmp;
        }
        return dp[i][j];
    }
}
```
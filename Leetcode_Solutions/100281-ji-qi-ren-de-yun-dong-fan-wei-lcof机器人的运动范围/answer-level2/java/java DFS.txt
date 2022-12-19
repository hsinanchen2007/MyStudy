### 解题思路
标准DFS  套模板就可以了。

### 代码

```java
class Solution {
    public int movingCount(int m, int n, int k) {
        boolean[][] visited = new boolean[m][n];
        return dfs(0,0,m,n,k,visited);
    }
    private int getSum(int x){
        int res = 0;
        while(x > 0){
            res += x%10;
            x = x/10;
        }
        return res;
    }
    private int dfs(int x,int y,int m,int n,int k,boolean[][] visited){
        if ((getSum(x)+getSum(y)) > k || x < 0 || x >= m || y < 0 || y >= n || visited[x][y]){
            return 0;
        }
        visited[x][y] = true;
        return 1+dfs(x+1,y,m,n,k,visited)+dfs(x,y+1,m,n,k,visited);
    }
}









```
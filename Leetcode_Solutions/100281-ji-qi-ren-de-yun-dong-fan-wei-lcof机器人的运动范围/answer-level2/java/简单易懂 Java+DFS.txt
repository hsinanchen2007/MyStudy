解题思路：
使用深度优先搜索（Depth First Search，DFS）方法进行求解。回溯是深度优先搜索的一种特例，它在一次搜索过程中需要设置一些本次搜索过程的局部状态，并在本次搜索结束之后清除状态。而普通的深度优先搜索并不需要使用这些局部状态，虽然还是有可能设置一些全局状态。
```
class Solution {
    private static final int[][] next = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    private int cnt = 0;
    private int m;
    private int n;
    private int k;
   
    public int movingCount(int m, int n, int k) {

        this.m = m;
        this.n = n;
        this.k = k;
        int cal;
        boolean[][] flag = new boolean[m][n];
        dfs(0,0,flag);
        return cnt;
    }
    private void dfs(int i, int j,boolean[][] flag ) {
     
        if (i < 0 || i >= m || j< 0 || j >= n || flag[i][j]) {
            return;
        }
        if(cal(i) + cal(j) > k) {
            return;
        }
        cnt++;
        flag[i][j] = true;
        for(int p = 0; p < 4; p++) {
            int newi= i + next[p][0];
            int newj= j + next[p][1];
            dfs(newi , newj , flag);
        }
    }
    private int cal(int num) {
        int ref = 0;
        while(num > 0) {
            ref += num % 10;
            num /= 10;
        }
        return ref;
    }
}
```

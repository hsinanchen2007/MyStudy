```
class Solution {
    int[][] go = {{0, 1}, {0, -1}, {1, 0}, {0, 1}};
    boolean[][] flag;
    int cnt = 0;
    public int movingCount(int m, int n, int k) {
        flag = new boolean[m][n];
        dfs(0, 0, m, n, k);
        return cnt;
    }
    private void dfs(int i, int j, int m, int n, int k) {
        if(i < 0 || j < 0 || i == m || j == n || flag[i][j]) {
            return;
        }
        if(cal(i) + cal(j) > k) {
            return;
        }
        cnt++;
        flag[i][j] = true;
        for(int p = 0; p < 4; p++) {
            dfs(i + go[p][0], j + go[p][1], m, n, k);
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

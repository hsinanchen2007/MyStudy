思路
[螺旋矩阵](https://leetcode-cn.com/problems/spiral-matrix/solution/luo-xuan-ju-zhen-by-leetcode/)

# 仿写
```
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] ans = new int[n][n];
        int[] dr = new int[]{0,1,0,-1};
        int[] dc = new int[]{1,0,-1,0};
        boolean[][] seen = new boolean[n][n];
        int r = 0, c = 0, di = 0;
        for(int i = 1; i <= n * n; i++){
            ans[r][c] = i;
            seen[r][c] = true;
            int cr = r + dr[di];
            int cc = c + dc[di];
            if (0 <= cr && cr < n && 0 <= cc && cc < n && !seen[cr][cc]){
                r = cr;
                c = cc;
            } else {
                di = (di + 1) % 4;
                r += dr[di];
                c += dc[di];
            }
        }
    return ans;
    }
}


class Solution {
    public int[][] generateMatrix(int n) {
        int[][] ans = new int[n][n];
        int r1 = 0, r2 = n - 1;
        int c1 = 0, c2 = n - 1;
        int i = 0; 
        while (r1 <= r2 && c1 <= c2) {
            for (int c = c1; c <= c2; c++) ans[r1][c] = ++i;
            for (int r = r1 + 1; r <= r2; r++) ans[r][c2] = ++i;
            if (r1 < r2 && c1 < c2) {
                for (int c = c2 - 1; c > c1; c--) ans[r2][c] = ++i;
                for (int r = r2; r > r1; r--) ans[r][c1] = ++i;
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return ans;
    }
}
```


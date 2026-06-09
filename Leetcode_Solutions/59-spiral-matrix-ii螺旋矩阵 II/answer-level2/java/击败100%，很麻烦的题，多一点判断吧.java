```
class Solution {
    public int[][] generateMatrix(int n) {
        // 4 directions
        int[][] res = new int[n][n];
        int num = 1;
        for(int r = 0; r <= n / 2; ++ r) {
            for(int i = r; i <= n - 1 - r; ++ i) {
                res[r][i] = num;
                num ++;
                if(num > n * n)
                    return res;
            }

            for(int i = r + 1; i <= n - 1 - r; ++ i) {
                res[i][n - 1 - r] = num;
                num ++;
                if(num > n * n)
                    return res;
            }

            for(int i = n - 2 - r; i >= r; -- i) {
                res[n - r - 1][i] = num;
                num ++;
                if(num > n * n)
                    return res;
            }

            for(int i = n - 2 - r; i >= r + 1; -- i) {
                res[i][r] = num;
                num ++;
                if(num > n * n)
                    return res;
            }
        }
        return res;
    }
}
```

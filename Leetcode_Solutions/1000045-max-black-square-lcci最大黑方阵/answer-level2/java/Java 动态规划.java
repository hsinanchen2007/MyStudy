```
public int[] findSquare(int[][] matrix) {
        int m = matrix.length;
        int n = 0;
        if (m == 0 || (n = matrix[0].length) == 0) {
            return new int[0];
        }
        
        int[] res = new int[3];
        int[][] dp1 = new int[m][n];
        int[][] dp2 = new int[m][n];
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    continue;
                }
                if (i == 0 && j == 0) {
                    dp1[i][j] = dp2[i][j] = 1;
                } else if (i == 0) {
                    dp1[i][j] = dp1[i][j-1] + 1;
                    dp2[i][j] = 1;
                } else if (j == 0) {
                    dp1[i][j] = 1;
                    dp2[i][j] = dp2[i-1][j] + 1;
                } else {
                    dp1[i][j] = dp1[i][j-1] + 1;
                    dp2[i][j] = dp2[i-1][j] + 1;
                }
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    continue;
                }
                
                int t = Math.min(dp1[i][j], dp2[i][j]);
                if (t > 0) {
                    for(int k = t; k > 0; k--) {
                        int s = Math.min(dp1[i- k + 1][j], dp2[i][j - k + 1]);
                        if (s >= k && k > res[2]) {
                            res[2] = k;
                            res[0] = i - k + 1;
                            res[1] = j - k + 1;
                            break;
                        }
                    }
                }
            }
        }
        
        if (res[2] == 0) {
            return new int[0];
        }
        
        return res;
    }
```

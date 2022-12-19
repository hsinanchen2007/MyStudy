```
public static int test1(int m, int n) {
        if (m == 0 || n == 0) {
            return 0;
        }
        int[] state = new int[m];
        Arrays.fill(state, 1);
        for (int j = 1; j < n; j++) {
            for (int i = 1; i < m; i++) {
                state[i] += state[i - 1];
            }
        }
        return state[m - 1];
    }
```
```
public static int test(int m, int n){
        if (m == 0 || n == 0){
            return 0;
        }
        int[][] state = new int[n][m];
        state[0][0] = 1;
        for (int i = 1; i < m; i++){
            state[0][i] = 1;
        }
        for (int j = 1; j < n; j++){
            state[j][0] = 1;
        }
        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                state[i][j] = state[i - 1][j] + state[i][j - 1];
            }
        }
        return state[n - 1][m - 1];
    }
```

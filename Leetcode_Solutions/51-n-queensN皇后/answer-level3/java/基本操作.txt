```
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> res = new ArrayList<>();
        backTrack(res, new int[n][n], 0, n);
        return res;
    }

    void backTrack(List<List<String>> res, int[][] arr, int j, int n) {
        if (j == n) {
            res.add(to(arr));
        } else {
            for (int i = 0; i < n; i++) {
                if (ok(arr, i, j, n)) {
                    arr[i][j] = 1;
                    backTrack(res, arr, j + 1, n);
                    arr[i][j] = 0;
                }
            }
        }
    }

    boolean ok(int[][] arr, int i, int j, int n) {
        for (int b = 0; b < j; b++) {
            if (arr[i][b] == 1) return false;
        }
        for (int a = i - 1, b = j - 1; a >= 0 && b >= 0; a--, b--) {
            if (arr[a][b] == 1) return false;
        }
        for (int a = i + 1, b = j - 1; a < n && b >= 0; a++, b--) {
            if (arr[a][b] == 1) return false;
        }
        return true;
    }

    List<String> to(int[][] arr) {
        List<String> res = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            StringBuilder builder = new StringBuilder();
            for (int j = 0; j < arr.length; j++) {
                if (arr[j][i] == 0) builder.append('.');
                else builder.append('Q');
            }
            res.add(builder.toString());
        }
        return res;
    }
```

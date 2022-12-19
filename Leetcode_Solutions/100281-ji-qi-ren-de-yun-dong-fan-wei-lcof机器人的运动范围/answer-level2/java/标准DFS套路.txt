```
private int res = 0;
    int[][] dirs = new int[][] {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    public int movingCount(int m, int n, int k) {
        int[][]visited = new int[m][n];
        dfs(0, 0, m, n, k, visited);

        return res;
    }

    private void dfs(int i, int j, int m, int n, int k, int[][]visited) {
        res++;
        visited[i][j] = 1;
        for (int[] dir : dirs) {
            int newRow = i + dir[0];
            int newCol = j + dir[1];

            if (isValidPos(newRow, newCol, m, n, k) && visited[newRow][newCol] == 0) {

                dfs(newRow, newCol, m, n, k, visited);
            }
        }
    }

    private boolean isValidPos(int i, int j, int m, int n, int k) {
        if (i < 0 || j < 0 || i == m || j == n) {
            return false;
        }

        int sum = 0;
        while (i > 0) {
            sum += i % 10;
            i = i / 10;
        }

        while (j > 0) {
            sum += j % 10;
            j = j / 10;
        }

        return sum <= k;
    }
```

BFS解法：时间5ms

```
class Solution {
    public int movingCount(int m, int n, int k) {
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        Queue<int[]> queue = new LinkedList<>();
        boolean[][] seen = new boolean[m][n];
        int res = 1;
        queue.offer(new int[]{0, 0});
        seen[0][0] = true;
        while (!queue.isEmpty()) {
            int[] node = queue.poll();
            int x = node[0], y = node[1];
            for (int j = 0; j < 4; j++) {
                int newX = x + dx[j], newY = y + dy[j];
                if (newX<0 || newX>=m || newY<0 || newY>=n || seen[newX][newY] || numSum(newX, newY)>k)
                    continue;
                else {
                    queue.offer(new int[]{newX, newY});
                    res++;
                    seen[newX][newY] = true;
                }
            }
        }
        return res;
    }
    public int numSum(int num1, int num2) {
        int sum = 0;
        while (num1 != 0 || num2 != 0) {
            sum += num1 % 10;
            sum += num2 % 10;
            num1 /= 10;
            num2 /= 10;
        }
        return sum;
    }
}
```

DFS解法：时间1ms

```
class Solution {
    public int movingCount(int m, int n, int k) {
        boolean[][] seen = new boolean[m][n];
        return dfs(0, 0, m, n, k, seen);
    }
    public int dfs(int i, int j, int m, int n, int k, boolean[][] seen) {
        if (i < 0 || i >= m || j < 0 || j >= n || seen[i][j] || numSum(i, j) > k)
            return 0;
        seen[i][j] = true;
        return 1 + dfs(i + 1, j, m, n, k, seen) + 
            dfs(i - 1, j, m, n, k, seen) + 
            dfs(i, j + 1, m, n, k, seen) + 
            dfs(i, j - 1, m, n, k, seen);
    }
    public int numSum(int num1, int num2) {
        int sum = 0;
        while (num1 != 0 || num2 != 0) {
            sum += num1 % 10;
            sum += num2 % 10;
            num1 /= 10;
            num2 /= 10;
        }
        return sum;
    }
}
```



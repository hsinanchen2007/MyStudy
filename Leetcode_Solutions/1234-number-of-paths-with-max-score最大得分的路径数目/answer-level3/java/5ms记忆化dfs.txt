思路：
1、在常规dfs的过程中记录了一下路径和以及方案数
2、递归的语义是从当前位置出发到达终点能得到的最大路径和以及最大路径和出现的次数
```

    private class Result {

        int sum;

        long count;

        Result(int s, long c) {
            sum = s;
            count = c;
        }
    }

    private int n;

    // 方向数组
    private int[][] directions = new int[][]{{-1, 0}, {0, -1}, {-1, -1}};

    private final long MOD = 1000000007;

    // 缓存
    private Result[][] cache;

    public int[] pathsWithMaxScore(List<String> board) {
        n = board.size();
        cache = new Result[n][n];
        // 处理输入
        char[][] chars = new char[n][n];
        int index = 0;
        for (String s : board) {
            chars[index++] = s.toCharArray();
        }
        Result res = dfs(chars, n - 1, n - 1);
        return new int[]{res.sum, (int) (res.count)};
    }

    private Result dfs(char[][] board, int i, int j) {
        if (board[i][j] == 'E') {
            return new Result(0, 1);
        }
        if (cache[i][j] != null) {
            return cache[i][j];
        }
        int sum = 0;
        long count = 0;
        int val = board[i][j] != 'S' ? board[i][j] - '0' : 0;
        for (int[] direction : directions) {
            int x = i + direction[0];
            int y = j + direction[1];
            if (verify(x, y) && board[x][y] != 'X') {
                Result res = dfs(board, x, y);
                // 过滤走不通过的情况
                if (res.count != 0) {
                    // 找到最大路径和以及出现的次数
                    if (res.sum > sum) {
                        sum = res.sum;
                        count = res.count;
                    } else if (res.sum == sum) {
                        count += res.count;
                    }
                }
            }
        }
        return cache[i][j] = new Result(sum + val, count % MOD);
    }

    // 数组角标越界检查
    private boolean verify(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
```



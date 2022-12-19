***代码中有详细注释***

解题思路：类似floodfill,先找到'O'联通的区块，再判断每个区块是否可以被置为'X'。

分析题意：需要找到不被"X"包围的由"O"组成的区域。所以不包围就是"O"联通的区域存在“出口”--边界的点. 

所以分两步：
1. 找到由0联通的区域---上下左右,四个方向查找,方向随意。
2. 每个区域是否存在边界点。

下面请看详细代码。
PS：第一次写题解.....，该代码有优化空间，主要分享思路.欢迎探讨，指教。
```
private int m, n;
    //四个方向递归搜索
    private int[][] visited = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    //四个方向中搜索过的点就不再访问了
    private boolean[][] used;
    //把所有由0联通的区域都找出来，一块，一块的。
    public List<List<Pair<Integer, Integer>>> resultList = new ArrayList();

    public void solve(char[][] board) {
        if (board == null) {
            return;
        }

        m = board.length;
        if (m == 0) {
            return;
        }
        n = board[0].length;
        if (n == 0) {
            return;
        }
        used = new boolean[m][n];
        //从左上角出发遍历每个是‘O’的位置开始，且搜索过的点跳过（!used[i][j]）
        // searchConnection 每个点四个方向（visited[][]）递归的的搜。
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !used[i][j]) {
                    List<Pair<Integer, Integer>> temp = searchConnection(board, i, j, new ArrayList());
                    resultList.add(temp);
                }
            }
        }
        //处理结果；
        // 既处理找到的所有'O'组成的联通区域
        for (int i = 0; i < resultList.size(); i++) {
            List<Pair<Integer, Integer>> subList = resultList.get(i);
            //该由0联通的区域 是否存在其中的某个点是边界的情况
            boolean isHandle = true;
            if (subList != null && subList.size() > 0) {
                for (int j = 0; j < subList.size(); j++) {
                    Pair<Integer, Integer> cell = subList.get(j);
                    if (cell != null && cell.getKey() != null && cell.getValue() != null) {
                        if (isEdge(cell.getKey(), cell.getValue())) {
                            isHandle = false;
                            break;
                        }
                    }
                }
            }
            //该区域不存在边界点
            if (isHandle) {
                for (int j = 0; j < subList.size(); j++) {
                    Pair<Integer, Integer> cell = subList.get(j);
                    if (cell != null && cell.getKey() != null && cell.getValue() != null) {
                        //设置成'X'
                        board[cell.getKey()][cell.getValue()] = 'X';
                    }
                }
            }

        }

    }

    /**
     * 是否是边界点
     *
     * @param x
     * @param y
     * @return
     */
    private boolean isEdge(int x, int y) {
        return x == 0 || x == m - 1 || y == 0 || y == n - 1;
    }

    /**
     * 是否在图版内
     *
     * @param x
     * @param y
     * @return
     */
    private boolean inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }


    /**
     * @param board  图版
     * @param startX 当前行坐标
     * @param startY 当前列坐标
     * @param result 用于保存一次O"块"中每个坐标点。
     * @return
     */
    public List<Pair<Integer, Integer>> searchConnection(char[][] board, int startX, int startY, List<Pair<Integer, Integer>> result) {
        used[startX][startY] = true;
        if (board[startX][startY] == 'O') {
            Pair<Integer, Integer> pair = new Pair(startX, startY);
            result.add(pair);
            for (int i = 0; i < 4; i++) {
                int nextX = startX + visited[i][0];
                int nextY = startY + visited[i][1];
                if (inArea(nextX, nextY) && !used[nextX][nextY] && board[nextX][nextY] == 'O') {
                    searchConnection(board, nextX, nextY, result);
                }
            }
        }
        return result;
    }
```

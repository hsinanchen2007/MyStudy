本质还是用的匈牙利算法。有两点改变。只讲改变，不讲匈牙利算法。

第一点：构造的邻接矩阵`Graph[][]`，几乎没什么用，不仅如此还要花费时间来构造矩阵，于是我想干脆不要这个邻接矩阵，直接用棋盘`board[][]`表示还简单点，`true`表示完好，`false`表示坏掉，相邻的都是好的就可以相连，有坏的就不能相连。这种判断和`Graph`没什么差别，但是可以去掉一堆构造`Graph`的代码。`Java`相当明显。

第二点：算法中的查找方法（`find`），是在遍历点集V2，但是循环里面有一个`if`语句判断是不是相连的。既然如此我何必要`for`循环所有的点呢。直接遍历点v1的上下左右不就行了。这又要说到`Graph`了，你可以发现，`Graph`里面每行最多只有四个是`true`的，因为相连的只有上下左右，因此原始方法很多遍历都是无用的（尽管时间开销不是很大，因为只有一个`if`判断，不相连就继续，但我依然觉得没必要遍历那么多。）

我用两种提交的时间都是1ms，但是这种代码相对少（前提是规范编码，别说什么大括号不要，少一行那种话）。仅供参考。

### 匈牙利算法
```java
// 匈牙利算法
class Solution {
    private boolean[] visit;// visit[v2]=true表示点v2访问过
    private int[] link;// link[v2]=v1表示当前与v2相连的点是v1
    // 其中v1属于点集V1，v2属于点集V2，数组下标从0开始

    private boolean[][] board;// 棋盘，false表示坏的
    private int[][] dir = { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };

    public int domino(int n, int m, int[][] broken) {
        if (broken.length == 0) {// 无坏掉的
            return n * m >> 1;
        }

        // 初始化棋盘，false表示坏掉
        board = new boolean[n][m];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(board[i], true);// 初始全部完好
        }
        for (int[] b : broken) {
            board[b[0]][b[1]] = false;// 设置坏掉的
        }

        return hungary();// 匈牙利算法计算最大骨牌数
    }

    private int hungary() {// 匈牙利算法，返回最大匹配数
        int n = board.length, m = board[0].length;
        visit = new boolean[n * m];
        link = new int[n * m];
        Arrays.fill(link, -1);
        int ret = 0;
        // 遍历点集V1中的点
        for (int r = 0; r < n; ++r) {
            for (int c = ((r & 1) == 0 ? 0 : 1); c < m; c += 2) {
                if (board[r][c]) {
                    Arrays.fill(visit, false);
                    if (find(r, c)) {
                        ++ret;
                    }
                }
            }
        }
        return ret;// 返回最大匹配数
    }

    private boolean find(int row, int col) {
        int n = board.length, m = board[0].length;
        for (int[] d : dir) {// 四个相邻点
            int r = row + d[0];
            int c = col + d[1];
            if (r < 0 || r >= n || c < 0 || c >= m) {
                continue;// 越界
            }
            int v2 = r * m + c;
            if (board[r][c] && !visit[v2]) {// 完好并且未访问过
                visit[v2] = true;
                if (link[v2] == -1 || find(link[v2] / m, link[v2] % m)) {
                    link[v2] = row * m + col;
                    return true;// 找到增广路径
                }
            }
        }
        return false;// 找不到增广路径
    }
}
```

### 回溯算法（补充）
```java
// 回溯算法，适用于我这种菜鸟，不过看懂匈牙利也挺简单的。
class Solution {
    private int[][] board;// 棋盘
    private int n, m;// 行数，列数

    public int domino(	int n,
                        int m,
                        int[][] broken) {
		if (broken.length == 0) {
			return n * m >> 1;
		}

        board = new int[n][m];

        for (int[] b : broken) {
            board[b[0]][b[1]] = 2;// 坏掉
        }

        this.n = n;
        this.m = m;
        return backtrack(0, 0, 0);
    }

	// (r, c)当前位置，count已经放的骨牌数
    private int backtrack(	int r,
                            int c,
                            int count) {
        if (r >= n) {// 行越界，结束，返回最大值
            return count;
        }
        if (c >= m) {// 列越界
            return backtrack(r + 1, 0, count);// 转到下一行，骨牌数不变
        }
        if (board[r][c] != 0) {// 当前位置已经有骨牌或者坏掉
            return backtrack(r, c + 1, count);// 转到下一列，骨牌数不变
        }

        int count1 = 0;// 横放
        if (c + 1 < m && board[r][c + 1] == 0) {// 右边未出界并且可以放骨牌
            board[r][c] = board[r][c + 1] = 1;
            count1 = backtrack(r, c + 2, count + 1);// 转到下下一列，骨牌数加1
            board[r][c] = board[r][c + 1] = 0;// 复盘
        }

        int count2 = 0;// 竖放
        if (r + 1 < n && board[r + 1][c] == 0) {// 未出界并且可以放骨牌
            board[r][c] = board[r + 1][c] = 1;
            count2 = backtrack(r, c + 1, count + 1);// 转到下一列，骨牌数加1
            board[r][c] = board[r + 1][c] = 0;
        }

        int count3 = 0;// 不放
        if (count1 == 0 && count2 == 0) {// 无法放骨牌，不放
            count3 = backtrack(r, c + 2, count);// 转到下下一列，骨牌数不变
        }

        return Math.max(Math.max(count1, count2), count3);// 返回最大值
    }
}
```

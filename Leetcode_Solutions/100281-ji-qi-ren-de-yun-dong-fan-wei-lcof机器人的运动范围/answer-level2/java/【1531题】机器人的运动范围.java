**题意分析**
(1) 整个区域为 m 行 n 列的方格，注意是方格不是坐标点。
(2) 每次只能向上下左右四个方向移动一格，不能出格跳格。
(3) 所到达的格子坐标数位之和不能大于 k 。
(4) 问能达到的格子，也就是问所有机器人可以去到的格子。
*** 明显是搜索遍历类型题，本题需要注意的是对于格子的重复遍历以及边界值。

**方法一：广度优先搜索（BFS） + 队列**
思路：
(1) 搜索所有从 (0,0) 开始可以去到的格子，记录每个可以去到的格子数。
(2) 只需要考虑向坐标轴正方向的移动就可以覆盖遍历所有可能的格子。
(3) 根据队列弹出和加入符合条件的格子实现广度优先搜索找到所有符合条件的格子。
```
class Solution {
    public int movingCount(int m, int n, int k) {
        // 初始化可以到达的格子数为 1 ，默认的出发格子 (0,0) 。
        int ans = 1;
        // 方向向量，每个格子只考虑向 x 轴或者 y 轴的正方向前进一格。
        int[] dx = {1,0};
        int[] dy = {0,1};
        // 记录机器人已经走过的格子，避免重复计算，原点的格子不会重复。
        boolean[][] over = new boolean[n][m];
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0,0});
        while (!queue.isEmpty()) {
            // 取出当前机器人站的格子坐标。
            int[] curr = queue.poll();
            int x = curr[0], y = curr[1];
            for (int i = 0; i < 2; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                // 判断要去到的格子是否越界、是否符合 k 值、是否已经走过。
                if (newX >= n || newY >= m || sumDigits(newX) + sumDigits(newY) > k || over[newX][newY]) {
                    continue;
                }
                // 可达到的格子数 +1 ，并将新格子标记为走过。
                ans += 1;
                over[newX][newY] = true;
                queue.offer(new int[]{newX,newY});
            }
        }
        return ans;
    }

    private int sumDigits(int num) {
        // 计算输入数字的数位之和并返回。
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}
```

**方法二：深度优先搜索（DFS） + 递归**
思路：
(1) 直接将方法一种的队列换成栈可以实现一种深度优先搜索。
(2) 因为从原点开始每个格子只有两个正方向可以移动，所以递归每个格子的移动方向。
(3) 判断越界、不符合 k 值和已经走过的情况，记录每条移动路径的格子数返回。
```
class Solution {
    public int movingCount(int m, int n, int k) {
        // 记录机器人已经走过的格子，避免重复计算。
        boolean[][] over = new boolean[n][m];
        // 从 (0,0) 点的格子开始出发。
        return movingCount(m, n, k, 0, 0, over);
    }

    private int movingCount(int m, int n, int k, int x, int y, boolean[][] over) {
        // 判断当前格子是否越界、是否符合 k 值、是否已经走过。
        if (x >= n || y >= m || sumDigits(x) + sumDigits(y) > k || over[x][y]) {
            return 0;
        }
        // 将当前格子标记为走过。
        over[x][y] = true;
        // 从当前格子出发，深度优先搜索两条路径的格子数。
        return 1 + movingCount(m, n, k, x + 1, y, over) + movingCount(m, n, k, x, y + 1, over);
    }

    private int sumDigits(int num) {
        // 计算输入数字的数位之和并返回。
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}
```

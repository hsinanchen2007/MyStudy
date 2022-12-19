### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public static int maxDistance(int[][] grid) {
        int ans = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 0) {
                    ans = Math.max(BFS(grid, i, j), ans);
                }
            }
        }
        return ans == 0 ? -1 : ans;
    }

    private static int BFS(int[][] grid, int i, int j) {
       Queue<Pair<Integer, Integer>> queue = new LinkedList<>();
        queue.offer(new Pair<>(i, j));
        int res = 0;
        boolean[][] state = new boolean[grid.length][grid[0].length];
        while (!queue.isEmpty()) {
            if (res != 0) {
                return res;
            }
            int size = queue.size();
            for (int k = 0; k < size; k++) {
                Pair<Integer, Integer> node = queue.poll();
                int x = node.getKey(), y = node.getValue();
                if (grid[x][y] == 1) {
                    int num = Math.abs(x - i) + Math.abs(y - j);
                    if(res == 0){
                        res = num;
                    }else {
                        res = res > num ? num : res;
                    }
                } else {
                    if (x - 1 >= 0 && !state[x - 1][y]) {
                        queue.offer(new Pair<>(x - 1, y));
                        state[x - 1][y] = true;
                        if (y + 1 < grid[0].length && !state[x - 1][y + 1]) {
                            state[x - 1][y + 1] = true;
                            queue.offer(new Pair<>(x - 1, y + 1));
                        }
                        if (y - 1 >= 0 && !state[x - 1][y - 1]) {
                            queue.offer(new Pair<>(x - 1, y - 1));
                            state[x - 1][y - 1] = true;
                        }
                    }
                    if (x + 1 < grid.length && !state[x + 1][y]) {
                        state[x + 1][y] = true;
                        queue.offer(new Pair<>(x + 1, y));
                        if (y + 1 < grid[0].length && !state[x + 1][y + 1]) {
                            state[x + 1][y + 1] = true;
                            queue.offer(new Pair<>(x + 1, y + 1));
                        }
                        if (y - 1 >= 0 && !state[x + 1][y - 1]) {
                            state[x + 1][y - 1] = true;
                            queue.offer(new Pair<>(x + 1, y - 1));
                        }
                    }
                    if (y + 1 < grid[0].length && !state[x][y + 1]){
                        state[x][y + 1] = true;
                        queue.offer(new Pair<>(x, y + 1));
                    }
                    if (y - 1 >= 0 && !state[x][y - 1]){
                        state[x][y - 1] = true;
                        queue.offer(new Pair<>(x, y - 1));
                    }
                }
            }
        }
        return res;
    }
}
```
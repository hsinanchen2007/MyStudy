### 解题思路
思路很容易想到，利用广度优先搜索，但记得要维护一个已访问节点的坐标的集合

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int res = 0;
        Queue<Pair<Integer, Integer>> queue = new LinkedList<>();
        Set<Pair<Integer, Integer>> visited = new HashSet<>();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (!visited.contains(new Pair<>(i, j)) && grid[i][j] == 1) {
                    queue.add(new Pair<>(i, j));
                    visited.add(new Pair<>(i, j));
                    int temp = 0;
                    while (!queue.isEmpty()) {
                        Pair<Integer, Integer> pair = queue.poll();
                        temp++;
                        int row = pair.getKey();
                        int col = pair.getValue();
                        if (col > 0 && grid[row][col - 1] == 1 && !visited.contains(new Pair<>(row, col - 1))) {
                            queue.add(new Pair<>(row, col - 1));
                            visited.add(new Pair<>(row, col - 1));
                        }
                        if (col < grid[0].length - 1 && grid[row][col + 1] == 1 && !visited.contains(new Pair<>(row, col + 1))) {
                            queue.add(new Pair<>(row, col + 1));
                            visited.add(new Pair<>(row, col + 1));
                        }
                        if (row > 0 && grid[row - 1][col] == 1 && !visited.contains(new Pair<>(row - 1, col))) {
                            queue.add(new Pair<>(row - 1, col));
                            visited.add(new Pair<>(row - 1, col));
                        }
                        if (row < grid.length - 1 && grid[row + 1][col] == 1 && !visited.contains(new Pair<>(row + 1, col))) {
                            queue.add(new Pair<>(row + 1, col));
                            visited.add(new Pair<>(row + 1, col));
                        }
                    }
                    res = Math.max(temp, res);
                }
            }
        }
        return res;
    }
}
```
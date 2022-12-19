### 解题思路
``` java
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;

/**
 * 广度优先思路
 */
class Solution {
    public int orangesRotting(int[][] grid) {
        //result
        int res = 0;
        //记录坏橘子的传播范围
        int[][] range = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        //用Deque存储腐烂的橘子
        Deque<Integer> queue = new ArrayDeque<>();
        //用Map存储每个腐烂橘子的腐烂时间
        Map<Integer, Integer> time = new HashMap<>();
        //记录二维数组的行，列的长度
        int row = grid.length;
        int col = grid[0].length;
        //遍历二维数组，记录初始坏橘子
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == 2) {
                    int pos = r * col + c;
                    queue.add(pos);
                    time.put(pos, 0);
                }
            }
        }
        //开始橘子腐烂行动，广度优先搜索
        while (!queue.isEmpty()) {
            //从队列取出烂橘子
            int pos = queue.remove();
            //从上下左右四个方向传播
            for (int k = 0; k < 4; k++) {
                int nr = pos / col + range[k][0];
                int nc = pos % col + range[k][1];
                //如果烂橘子周围是新鲜橘子则进行腐烂
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 1) {
                    //新腐烂的橘子
                    grid[nr][nc] = 2;
                    int newPos = nr * col + nc;
                    //存入队列
                    queue.add(newPos);
                    time.put(newPos, time.get(pos) + 1);
                    //记录此刻的橘子腐烂时间
                    res = time.get(newPos);
                }
            }
        }
        //遍历二维数组查看是否有未腐烂的橘子
        for (int[] values : grid) {
            for (int v : values) {
                if (v == 1) {
                    return -1;
                }
            }
        }
        return res;
    }
}
```

### 解题思路
1 层序遍历，使用负值表示层数；
2 通过对比橘子数量，判断是否需要时间腐败以及是否全部腐败, 避免冗余循环；
3 设数组大小为n, 时空复杂度为O(n);

### 代码

```java
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int orangesRotting(int[][] grid) {
        int orangeCount = 0;
        Queue<Integer> rotQueue = new LinkedList<>();
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[0].length; j++) {
                if(grid[i][j] == 0) {
                    continue;
                }

                orangeCount++;
                if(grid[i][j] == 2) {
                    rotQueue.offer(i * grid[0].length + j);
                }
            }
        }

        rotQueue.offer(-1);

        int rotCount = 0;
        int minute = -1;
        while(!rotQueue.isEmpty()) {
            int position = rotQueue.poll();
            if(position == -1) {
                minute++;
                if(!rotQueue.isEmpty()) {
                    rotQueue.offer(-1);
                }
                continue;
            }
            rotCount++;

            int row = position / grid[0].length;
            int col = position % grid[0].length;
            if(row > 0 && grid[row - 1][col] == 1) {
                grid[row - 1][col] = 2;
                rotQueue.offer((row - 1) * grid[0].length + col);
            }

            if(col > 0 && grid[row][col - 1] == 1) {
                grid[row][col - 1] = 2;
                rotQueue.offer(row * grid[0].length + col - 1);
            }

            if(row < grid.length - 1 && grid[row + 1][col] == 1) {
                grid[row + 1][col] = 2;
                rotQueue.offer((row + 1) * grid[0].length + col);
            }

            if(col < grid[0].length - 1 && grid[row][col + 1] == 1) {
                grid[row][col + 1] = 2;
                rotQueue.offer(row * grid[0].length + col + 1);
            }
        }

        if(orangeCount != rotCount) {
            minute = -1;
        }

        return minute;
    }
}
```
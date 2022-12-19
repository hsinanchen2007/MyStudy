### 解题思路

BFS的思路，首先对二维数组进行一次遍历。把已经腐烂的橘子添加到队列中。

之后循环遍历队列，每次将新腐烂的橘子添加到队列中，并将它们的腐烂时间记为之前的时间 + 1

当队列为空时，说明已经没有可以腐烂的橘子了。

这时候遍历数组，如果还有好橘子，则返回-1.否则返回最后一次循环里面的腐烂时间。

### 代码

```java
class Orange {
    int i;
    int j;
    int minutes;
}

class Solution {

    public int orangesRotting(int[][] grid) {
        int minutes = 0;
        Queue<Orange> queue = new LinkedList<>();

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 2) {
                    Orange orange = new Orange();
                    orange.i = i;
                    orange.j = j;
                    orange.minutes = minutes;
                    queue.offer(orange);
                }
            }
        }

        while (queue.size() > 0) {
            Orange poll = queue.poll();

            int x = poll.i, y = poll.j;
            minutes = poll.minutes;

            if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                Orange orange = new Orange();
                orange.i = x - 1;
                orange.j = y;
                orange.minutes = minutes + 1;
                queue.offer(orange);
                grid[x - 1][y] = 2;
            }
            if (x + 1 < grid.length && grid[x + 1][y] == 1) {
                Orange orange = new Orange();
                orange.i = x + 1;
                orange.j = y;
                orange.minutes = minutes + 1;
                queue.offer(orange);
                grid[x + 1][y] = 2;
            }
            if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                Orange orange = new Orange();
                orange.i = x;
                orange.j = y - 1;
                orange.minutes = minutes + 1;
                queue.offer(orange);
                grid[x][y - 1] = 2;
            }
            if (y + 1 < grid[0].length && grid[x][y + 1] == 1) {
                Orange orange = new Orange();
                orange.i = x;
                orange.j = y + 1;
                orange.minutes = minutes + 1;
                queue.offer(orange);
                grid[x][y + 1] = 2;
            }

        }

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return minutes;
    }

}
```
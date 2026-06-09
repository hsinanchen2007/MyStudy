### 解题思路
(x, y)可以表示为整数k = x * rows + y
恢复这个坐标只需要：
x = k / rows;
y = k % rows;

### 代码

```java
class Solution {
    int[] dx = {1, 0, -1, 0};
    int[] dy = {0, 1, 0, -1};
    public int maxDistance(int[][] grid) {
        int cols = grid.length;
        int rows = grid[0].length;
        //队列存陆地
        Queue<Integer> queue = new LinkedList();
        //遍历一遍把陆地入队
        for(int i = 0; i < cols; i++) {
            for(int j = 0; j < rows; j++) {
                if(grid[i][j] == 1) {
                    //将横坐标和竖坐标结合成一个整数
                    queue.offer(i * rows + j);
                }
            }
        }
        int res = 0;
        //开始BFS
        while(!queue.isEmpty()) {
            int size = queue.size();
            //记录这一次遍历有没有将海洋转换为陆地
            boolean isMod = false;
            //这一层有多少个陆地
            for(int i = 0; i < size; i++) {
                int cur = queue.poll();
                //恢复横竖坐标
                int x = cur / rows;
                int y = cur % rows;
                //上下左右
                for(int k = 0; k < 4; k++) {
                    if(x + dx[k] < 0 || x + dx[k] >= cols || y + dy[k] < 0 || y + dy[k] >= rows) {
                        continue;
                    }
                    //填海造陆就不用额外数组记录是否访问过
                    if(grid[x + dx[k]][y + dy[k]] == 0) {
                        grid[x + dx[k]][y + dy[k]] = 1;
                        //将下一层的陆地位置入队
                        queue.offer((x + dx[k]) * rows + (y + dy[k]));
                        isMod = true;
                    }
                }
            }
            //这一层有修改过，结果+1
            if(isMod) {
                res++;
                isMod = false;
            }
        }
        return res == 0 ? -1 : res;
    }
}
```
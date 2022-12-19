### 解题思路
整体利用BFS思想
1 建立path类，存储每个网格四个方向的状态和当前网格所在位置
2 map中存储每个街道的行走轨迹，例如:left和right为true,代表的第一种街道
3 BFS,将符合要求的路径入队列，见代码处解释

### 代码

```java
class Solution {
     class path {
         //四个方向，false为closed,true为open,只有open状态方可行走
        boolean left;
        boolean right;
        boolean up;
        boolean down;
        int row;
        int col;
        //省略get and set方法
    }
    public boolean hasValidPath(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        HashMap<Integer, path> map = new HashMap<>();
        for (int i = 1; i <= 6; i++) {
            path p = new path();
            if (i == 1) {
                p.setLeft(true);
                p.setRight(true);
            }
            if (i == 2) {
                p.setUp(true);
                p.setDown(true);
            }
            if (i == 3) {
                p.setLeft(true);
                p.setDown(true);
            }
            if (i == 4) {
                p.setRight(true);
                p.setDown(true);
            }
            if (i == 5) {
                p.setLeft(true);
                p.setUp(true);
            }
            if (i == 6) {
                p.setRight(true);
                p.setUp(true);
            }
            map.put(i, p);
        }
        Queue<path> queue = new LinkedList<>();
        queue.offer(map.get(grid[0][0]));
        boolean[][] visited = new boolean[m][n];//记录已经访问过的节点
        while (!queue.isEmpty()) {
            path pre = queue.poll();
            int row = pre.getRow(), col = pre.getCol();
            if (row == m - 1 && col == n - 1)//走到终点，返回true
                return true;
            path cur;
            if (pre.isRight() && col < n - 1 && !visited[row][col + 1]) {//right
                //若前一条街道的右边方向open，往右走
                cur = map.get(grid[row][col + 1]);
                cur.setCol(col + 1);
                cur.setRow(row);
                if (cur.isLeft()) {//由于前一条路径右边为open,故只有当前网格的左边为open时才能进队
                    queue.offer(cur);
                    visited[row][col + 1] = true;
                }

            } 
             if (row > 0 && !visited[row - 1][col] && pre.isUp()) {//up
                //若前一条街道的上边方向open，可往上走
                cur = map.get(grid[row - 1][col]);
                cur.setCol(col);
                cur.setRow(row - 1);
                if (cur.isDown()) {//由于前一条路径上边为open,故只有当前网格的下边为open时才能进队
                    queue.offer(cur);
                    visited[row - 1][col] = true;
                }
            } 
             if (row < m - 1 && !visited[row + 1][col] && pre.isDown()) {//down
                //若前一条街道的下边方向open，可往下走
                cur = map.get(grid[row + 1][col]);
                cur.setCol(col);
                cur.setRow(row + 1);
                if (cur.isUp()) {//由于前一条路径下边为open,故只有当前网格的上边为open时才能进队
                    queue.offer(cur);
                    visited[row + 1][col] = true;
                }
            } 
             if (pre.isLeft() && col > 0 && !visited[row][col - 1]) {//left
                //若前一条街道的左边方向open，可往左走
                cur = map.get(grid[row][col - 1]);
                cur.setCol(col - 1);
                cur.setRow(row);
                if (cur.isRight()) {//由于前一条路径左边为open,故只有当前网格的右边为open时才能进队
                    queue.offer(cur);
                    visited[row][col - 1] = true;
                }
            }
            visited[row][col] = true;//记录当前访问位置
        }
        return false;

    }
}
```
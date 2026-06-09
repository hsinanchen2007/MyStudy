### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    
    class Point {
        int x;
        int y;

        Point(int x, int y, int val) {
            this.x = x;
            this.y = y;
            mark[x][y] = val;
        }

        int getVal() {
            return mark[x][y];
        }

        @Override
        public String toString() {
            return "x: " + x + "  y:" + y + "  val: " + getVal();
        }
    }

    private static final int LAND = 1;
    // 方向数组
    private static final int dicSize = 4;
    private static final int[] xDic = new int[]{-1, 0, 1, 0};
    private static final int[] yDic = new int[]{0, -1, 0, 1};

    private int[][] mark;

    public int maxDistance(int[][] grid) {
        if (null == grid || 0 == grid.length || 0 == grid[0].length)
            return -1;
        // init param
        int rowSize = grid.length;
        int colSize = grid[0].length;
        Queue<Point> queue = new LinkedList<>();
        mark = new int[rowSize][colSize];

        for(int x=0; x< rowSize; ++x) {
            for(int y=0; y< colSize; ++y) {
                if (LAND == grid[x][y]) {
                    queue.add(new Point(x, y, 0));
                }
            }
        }

        int maxDis = -1;
        while(!queue.isEmpty()) {
            Point p = queue.poll();
            System.out.println(p);
            for(int i=0; i<dicSize; ++i) {
                int newX = p.x + xDic[i];
                int newY = p.y + yDic[i];
                int newVal = p.getVal() + 1;

                if (newX<0 || newY<0 || newX>= rowSize || newY>= colSize || LAND == grid[newX][newY] || mark[newX][newY] > 0 )
                    continue;
                queue.add(new Point(newX, newY, newVal));
                maxDis = Math.max(maxDis, newVal);
            }
        }
        return maxDis;
    }
}
```
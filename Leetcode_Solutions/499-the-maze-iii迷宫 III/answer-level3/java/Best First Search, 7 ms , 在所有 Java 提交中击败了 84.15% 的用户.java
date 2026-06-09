### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
        class Cell implements Comparable<Cell>{
        int x;
        int y;
        int val;
        String path;
        Cell(int x, int y, int val, String p) {
            this.x = x;
            this.y = y;
            this.val = val;
            this.path = p;
        }
        @Override
        public int compareTo(Cell c) {
            if (this.val == c.val) {
                return this.path.compareTo(c.path);
            }
            return this.val < c.val ? -1 : 1;
        }
    }
    private int[][] dirs = new int[][]{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    private String[] dChar = new String[]{"l", "r", "d", "u"};
    public String findShortestWay(int[][] maze, int[] ball, int[] hole) {
        int m = maze.length, n = maze[0].length;
        boolean[][] expanded = new boolean[m][n];
        int[][] dis = new int[m][n];
        PriorityQueue<Cell> minHeap = new PriorityQueue<>();
        Map<Integer, List<int[]>> parent = new HashMap<>();
        minHeap.offer(new Cell(ball[0], ball[1], 0, ""));
        while (minHeap.size() > 0) {
            Cell cur = minHeap.poll();
            if (expanded[cur.x][cur.y]) {
                continue;
            }
            expanded[cur.x][cur.y] = true;
            if (cur.x == hole[0] && cur.y == hole[1]) {
                return cur.path;
            }
            for (int i = 0; i < 4; i++) {
                int[] next = getNext(cur.x, cur.y, i, maze, hole);
                if (expanded[next[0]][next[1]]){
                    continue;
                }
                minHeap.offer(new Cell(next[0], next[1], next[2] + cur.val, cur.path + dChar[i]));

            }
        }
        return "impossible";
    }


    private int[] getNext(int i, int j, int dir, int[][] maze, int[] hole) {
        int dis = 0;
        while (!isBound(i + dirs[dir][0], j + dirs[dir][1], maze)) {
            i = i + dirs[dir][0];
            j = j + dirs[dir][1];
            dis++;
            if (i == hole[0] && j == hole[1]) {
                return new int[]{i, j, dis};
            }
        }
        return new int[]{i, j, dis};
    }
    private boolean isBound(int i, int j, int[][] maze) {
        if (i < 0 || i >= maze.length || j < 0 || j >= maze[0].length || maze[i][j] == 1) {
            return true;
        }
        return false;
    }
}
```
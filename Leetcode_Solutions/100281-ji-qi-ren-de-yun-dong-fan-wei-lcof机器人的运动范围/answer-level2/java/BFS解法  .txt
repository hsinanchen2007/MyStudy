### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
 

    boolean[][] hadVisited;

    int canVisitCnt = 0;

    private static List<Dir> dirs;

    int k;
    int MAX_X;
    int MAX_Y;

    private Queue<Dir> queue = new ArrayDeque<>(8);

    static class Dir {

        private int x;

        private int y;

        public Dir(int x, int y) {

            this.x = x;
            this.y = y;
        }

        public int getX() {

            return x;
        }

        public int getY() {

            return y;
        }
    }

    /**
     * 上下左右4个方向移动
     */
    private void initDirs() {

        dirs = new ArrayList<>(8);
        dirs.add(new Dir(0, 1));
        
        dirs.add(new Dir(1, 0));
       
    }

  
    public int movingCount(int m, int n, int k) {

        initDirs();
        MAX_X = m;
        MAX_Y = n;
        hadVisited = new boolean[m][n];
        this.k = k;
        queue.add(new Dir(0, 0));
        Dir cur;
        while ((cur = queue.poll()) != null) {
            if (isVisited(cur)) {
                continue;
            }

            if (!canHoldHere(cur)) {
                continue;
            }

            canVisitCnt++;
            markVisited(cur);

            addNextLocations(cur);

        }

        return canVisitCnt;
    }

    private void addNextLocations(Dir cur) {

        for (Dir dir : dirs) {
            Dir tmp = new Dir(dir.x+cur.x, dir.y+cur.y);
            if (tmp.x >=MAX_X) {
                continue;
            }
            if ( tmp.y>=MAX_Y) {
                continue;
            }
            queue.add(tmp);
        }

    }

    private void markVisited(Dir dir) {

        hadVisited[dir.x][dir.y] = true;
    }

    private boolean isVisited(Dir dir) {

        return hadVisited[dir.x][dir.y];
    }

    private boolean canHoldHere(Dir dir) {

        int sum = 0;

        int t = dir.x;
        while (t / 10 != 0) {
            sum += t % 10;
            t = t / 10;
        }
        sum += t % 10;

        t = dir.y;
        while (t / 10 != 0) {
            sum += t % 10;
            t = t / 10;
        }
        sum += t % 10;

        return sum <= k;

    }
}
```
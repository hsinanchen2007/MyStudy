### 解题思路
    

### 代码

```java
class Solution {
    public int movingCount(int m, int n, int k) {
        Queue<Entry> q = new LinkedList<>();
        q.add(new Entry(0, 0));
        int cnt = 0;
        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            Arrays.fill(visited[i], false);
        }
        visited[0][0] = true;
        int[] dx = { 0, 1, 0, -1 };
        int[] dy = { 1, 0, -1, 0 };
        while (!q.isEmpty()) {
            Entry e = q.poll();
            cnt++;
            for (int l = 0; l < 4; l++) {
                int curX = e.x + dx[l];
                int curY = e.y + dy[l];
                if (curX < 0 || curX >= m || curY < 0 || curY >= n || visited[curX][curY]) {
                    continue;
                }
                visited[curX][curY] = true;
                Entry curE = new Entry(curX, curY);
                if (canReach(curE, k)) {
                    q.add(curE);
                }
            }
        }
        return cnt;
    }

    private boolean canReach(Entry e, int k) {
        int sum = 0;
        int x = e.x;
        int y = e.y;
        while (x != 0 || y != 0) {
            sum += (x % 10);
            sum += (y % 10);
            x /= 10;
            y /= 10;
            if (sum > k) {
                return false;
            }
        }
        return true;
    }

    class Entry {
        int x;
        int y;

        public Entry(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
```
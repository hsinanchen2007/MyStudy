### 解题思路
二分法和小顶堆

### 代码

```java
class Pair {
    int r, c, val;
    public Pair(int r, int c, int val) {
        this.r = r;
        this.c = c;
        this.val = val;
    }
}

class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int[] dx = new int[]{0, 1};
        int[] dy = new int[]{1, 0};
        int n = matrix.length, m = matrix[0].length;
        boolean[][] visited = new boolean[n][m];

        Queue<Pair> queue = new PriorityQueue<>(k, new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                return o1.val - o2.val;
            }
        });
        queue.add(new Pair(0, 0, matrix[0][0]));
        visited[0][0] = true;

        for (int i = 0; i < k - 1; i++) {
            Pair pair = queue.poll();
            int r = pair.r;
            int c = pair.c;

            for (int j = 0; j < 2; j++) {
                int nextr = r + dx[j];
                int nextc = c + dy[j];

                if(nextr < n && nextc < m && !visited[nextr][nextc]) {
                    visited[nextr][nextc] = true;
                    queue.add(new Pair(nextr, nextc, matrix[nextr][nextc]));
                }
            }
        }
        return queue.peek().val;
    }
}
```
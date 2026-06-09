```
 private static final int[][] dir = {{-1,0},{1,0},{0,-1},{0,1},{0,0}};
    public int minFlips(int[][] mat) {
        // 这里用到了 矩阵位压缩。因为不超过九位数，可以直接放到 int 里面。
        int start = 0;
        int m = mat.length;
        int n = mat[0].length;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                start |= mat[i][j] << (i * n + j);
            }
        }

        Queue<Integer> q = new LinkedList<>(Arrays.asList(start));
        Set<Integer> seen = new HashSet<>();
        for(int step = 0; !q.isEmpty(); ++step) {
            for(int sz = q.size(); sz > 0; --sz) {
                int cur = q.poll();
                if(cur == 0) {
                    return step;
                }
                for(int i = 0; i < m; ++i) {
                    for(int j = 0; j < n; ++j) {
                        int next = cur;
                        // 矩阵上每个位置都可以翻转。
                        for(int k = 0; k < 5; ++k) {
                            // filp the ceil(i,j) and it's neighbors;
                            int r = i + dir[k][0];
                            int c = j + dir[k][1];
                            if(r >= 0 && r < m && c >= 0 && c < n) {
                                next ^= 1 << (r * n + c);
                            }
                        }
                        if(seen.add(next)) { // if seen can add next.
                            q.offer(next); // we put the next to the queue.
                        }
                    }
                }
            }
        }
        return -1;
    }
```

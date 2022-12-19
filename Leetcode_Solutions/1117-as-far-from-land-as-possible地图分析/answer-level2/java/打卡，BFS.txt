    // 多源广搜
    class Solution {
        public int maxDistance(int[][] grid) {
            int m = grid.length;
            int n = grid[0].length;
            int res = -1;
            Queue<int[]> queue = new LinkedList<>();
            for(int i = 0;i < m;i++) {
                for(int j = 0;j < n;j++) {
                    if(grid[i][j] == 1) {
                        queue.offer(new int[]{i, j});
                    }
                }
            }
            HashSet<String> hs = new HashSet<>();
            int[] dx = {-1, 1, 0, 0};
            int[] dy = {0, 0, -1, 1};
            while(!queue.isEmpty()) {
                int size = queue.size();
                for(int i = 0;i < size;i++) {
                    int[] temp = queue.poll();
                    for(int j = 0;j < 4;j++) {
                        int x = temp[0] + dx[j];
                        int y = temp[1] + dy[j];
                        if(x >= 0 && x < m && y >= 0 && y < n && !hs.contains(x + "#" + y) && grid[x][y] == 0) {
                            hs.add(x + "#" + y);
                            queue.offer(new int[]{x, y});
                        }
                    }
                }
                if(!queue.isEmpty()) {
                    res++;
                }
            }
            return res == -1 ? -1 : res + 1;
        }
    }
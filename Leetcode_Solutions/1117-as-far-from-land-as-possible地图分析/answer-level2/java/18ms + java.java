class Solution {
    int N;
    int[][] grid;
    boolean[][] visited;
    public int maxDistance(int[][] grid) {
        N = grid.length;
        this.grid = grid;
        visited = new boolean[N][N];
        Queue<int[]> lands = new LinkedList<>();
        int[][] directions = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i = 0;i < N;++i) {
            for(int j = 0;j < N;++j) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    lands.add(new int[]{i, j, 0});
                    visited[i][j] = true;
                }
            }
        }

        int max = -1;
        while (!lands.isEmpty()) {
            int[] land = lands.poll();
            for(int[] direction : directions) {
                int x = direction[0] + land[0];
                int y = direction[1] + land[1];
                if(!valid(x, y)) continue;
                if(visited[x][y]) continue;
                if(grid[x][y] == 1) continue;
                int dis = land[2];
                lands.add(new int[]{x, y, dis + 1});
                max = dis + 1;
                visited[x][y] = true;
            }
        }
        return max;
    }
    private boolean valid(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N;
    }
}
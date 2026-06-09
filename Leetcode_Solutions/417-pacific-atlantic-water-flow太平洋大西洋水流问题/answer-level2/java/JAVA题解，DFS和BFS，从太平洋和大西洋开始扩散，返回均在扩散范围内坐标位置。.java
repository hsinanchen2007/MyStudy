```
class Solution {
    int m, n, nextI, nextJ;
    int direct[][] = {{-1,0,1,0},{0,1,0,-1}};
    Queue<int[]>queue = new LinkedList<>();
    public List<List<Integer>> pacificAtlantic(int[][] matrix) {
        List<List<Integer>>result = new ArrayList<>();
        m = matrix.length;
        if (m == 0) {
            return result;
        }
        n = matrix[0].length;
        boolean[][] Pacific = new boolean[m][n];
        boolean[][] Atlantic = new boolean[m][n];
        for (int i = 0; i < n; i++) {
            //dfs(matrix, 0, i, Pacific);
            bfs(matrix, 0, i, Pacific);
            //dfs(matrix, m-1, i, Atlantic);
            bfs(matrix, m-1, i, Atlantic);
        }
        for (int i = 0; i < m; i++) {
            //dfs(matrix, i, 0, Pacific);
            bfs(matrix, i, 0, Pacific);
            //dfs(matrix, i, n-1, Atlantic);
            bfs(matrix, i, n-1, Atlantic);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <n; j++) {
                if (Pacific[i][j] == true && Atlantic[i][j] ==true) {
                    result.add(Arrays.asList(i,j));
                }
            }
        }
        return result;
    }
    public void dfs(int[][] matrix, int i, int j, boolean[][]visited) {
        if (visited[i][j] == true) {
            return;
        }
        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            nextI = i + direct[0][k];
            nextJ = j + direct[1][k];
            if (nextI >=0 && nextI < m && nextJ >=0 && nextJ < n && matrix[nextI][nextJ] >= matrix[i][j]) {
                dfs(matrix, nextI, nextJ, visited);
            }
        }
    }
    public void bfs(int[][] matrix, int i, int j, boolean[][]visited) {
        if (visited[i][j] == true) {
            return;
        }
        queue.offer(new int[]{i, j});
        int curI, curJ;
        int[] pos;
        visited[i][j] = true;
        while (!queue.isEmpty()) {
            pos = queue.poll();
            curI = pos[0];
            curJ = pos[1];
            for (int k = 0; k < 4; k++) {
                nextI = curI + direct[0][k];
                nextJ = curJ + direct[1][k];
                if (nextI >=0 && nextI < m && nextJ >=0 && nextJ < n && matrix[nextI][nextJ] >= matrix[curI][curJ] && visited[nextI][nextJ] == false) {
                    queue.add(new int[]{nextI, nextJ});
                    visited[nextI][nextJ] = true;
                }
            }
        }
    }
}
```

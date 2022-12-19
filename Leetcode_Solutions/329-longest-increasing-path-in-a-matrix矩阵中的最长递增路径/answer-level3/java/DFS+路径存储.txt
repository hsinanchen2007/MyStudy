### 解题思路
写了好几次都超时，优化之后，勉强超过30%。
1. 用vivited来记录遍历过的点的最大递增路径。
2. 当某次dfs遇到该点时，直接返回，因此可以减少搜索时间。
3. 回溯时弄清楚你想如何保存状态。

### 代码

```java
class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        if (matrix.length == 0)
            return 0;
        int[][] vector = new int[][]{{1,0},{-1,0},{0,1},{0,-1}};
        int sum = 1;
        int[][] visited = new int[matrix.length][matrix[0].length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (visited[i][j] == 0){
                    List<int[]> list = new ArrayList<>();
                    list.add(new int[]{i,j});
                    int dfs = dfs(vector, i, j, matrix, list,visited);
                    if (dfs >= sum)
                        sum = dfs;
                }
            }
        }
        return sum;
    }

    private int dfs(int[][] vector,int i,int j,int[][] matrix,List<int[]> list,int[][] visited){
        if (visited[i][j] != 0)
            return visited[i][j];
        int max_len = 1;
        for (int[] ints : vector) {
            int r = i + ints[0];
            int c = j + ints[1];
            if (r >= 0 && r < matrix.length && c >= 0 && c < matrix[0].length && matrix[r][c] > matrix[i][j]){
                list.add(new int[]{i,j});
                int len = dfs(vector, r, c, matrix, list,visited) + 1;
                if (len >= max_len)
                    max_len = len;
                list.remove(list.size()-1);
            }
        }
        visited[i][j] = max_len;
        return max_len;
    }
}
```
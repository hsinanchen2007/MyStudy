很容易发现，其实这就是一个图的结构。

其中每个人是顶点，而人与人之间的关系是边。如果i和j两个人是朋友，其实就是i和j两个顶点之间存在边相连。

题目给出的矩阵实际上是一个邻接矩阵，因此这个题目就抽象成了已知邻接矩阵，求这个图的连通分量个数这样一个问题，就是一个模板题了，直接套模板代码即可。

```java
class Solution {
    public int findCircleNum(int[][] M) {
        boolean[] visited = new boolean[M.length];
        int ans = 0;
        for(int i = 0; i < M.length; i++) {
            if(!visited[i]) {
                ans++;
                dfs(M, i, visited);
            }
        }
        return ans;
    }

    private void dfs(int[][] M, int i, boolean[] visited) {
        visited[i] = true;
        for(int j = 0; j < M.length; j++) {
            if(!visited[j] && M[i][j] == 1) {
                dfs(M, j, visited);
            }
        }
    }
}
```
### 解题思路
1.非连通图，开始节点不唯一，遍历所有顶点；
2.每个顶点进行dfs；

### 代码

```java
class Solution {
    public static final int UNVISITED = 0;
    public static final int IS_FRIENTD = 1;
    public static final int VISITED = 1;

    public int findCircleNum(int[][] M) {
        int count = 0;
        if (null == M || M.length < 1) {
            return count;
        }

        int[] nodes = new int[M.length];
        for(int i = 0; i < nodes.length; i++) {
            if (nodes[i] == UNVISITED) {
                count++;
                dfs(i, M, nodes);
            }
        }
        return count;
    }

    private void dfs(int i, int[][] dp, int[] nodes) {
        nodes[i] = VISITED;
        for (int j = 0; j < dp.length; j++) {
            if (dp[i][j] == IS_FRIENTD && nodes[j] == UNVISITED) {
                dfs(j, dp, nodes);
            }
        }
    }
}
```
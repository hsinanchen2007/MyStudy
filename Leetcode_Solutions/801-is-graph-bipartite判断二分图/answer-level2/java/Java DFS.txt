### 解题思路
DFS 染色法，相邻节点的间的颜色不同
1.要考虑的情况非连通图的情况
2.利用HashMap存储已搜索的节点和节点的颜色


### 代码

```java
class Solution {
    public boolean isBipartite(int[][] graph) {
        HashMap<Integer,Integer> colors = new HashMap<>();
        int color = 1;
        // 对于图的所有点，都要进行搜索，以保证非连通图的情况
        for (int label = 0;label < graph.length;label ++) {
            // 已经染色过的点，不再进行搜索
            if(colors.containsKey(label)) continue;
            // dfs的 false 条件是 HashMap存储的颜色与要染色的颜色不同，即同一点有两种颜色
            if(!dfs(graph,label,colors,color)) return false;
        }
        return true;
    }

    private boolean dfs(int[][] graph ,int label, Map<Integer,Integer> colors, int color) {
        // 如果这个点之前染过色，则比较现在的颜色和要染色的颜色是否相同
        if(colors.containsKey(label)) return colors.get(label).equals(color);
        // 记录已经被染过色的点和颜色
        colors.put(label,color);
        // 对当前点的所有邻居都要进行染色
        for(int neighbor: graph[label]) {
            //  如果这个邻居已经有颜色了，并且邻居的颜色和现在正在染色的点的颜色不同，则跳过
            if(colors.containsKey(neighbor) && !colors.get(neighbor).equals(color)) continue;
            // 对相邻点，染不同的颜色
            if(!dfs(graph,neighbor,colors,-1*color)) return false;
        }
        return true;
    }
}
```
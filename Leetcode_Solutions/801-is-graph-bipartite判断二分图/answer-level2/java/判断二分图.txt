其实就是染色问题：保证在遍历的过程中：前后遍历的两个顶点染不一样的颜色，一旦不满足就返回false退出遍历
创建一个colors数组来存储每个顶点的染色情况
1 BFS
```java
class Solution {
    public boolean isBipartite(int[][] graph) {
        int v = graph.length;
        int[] colors = new int[v];
        boolean[] visited = new boolean[v];
        for(int i = 0; i < v; i++) {
            colors[i] = -1;
        }
        for(int i = 0; i < v; i++) {
            if(colors[i] == -1) {
                if(!bfs(i, graph, 0, colors)) {
                    return false;
                }
            }
        }
        return true;
    }
    private boolean bfs(int v, int[][] graph,int color, int[] colors) {
        Queue<Integer> queue = new LinkedList();
        queue.add(v);
        colors[v] = 0;
        while(!queue.isEmpty()) {
            int e = queue.poll();
            for(int w: graph[e]) {
                if(colors[w] == -1) {
                    queue.add(w);
                    colors[w] = 1 - colors[e];
                } else if(colors[w] == colors[e]) {
                    return false;
                }
            }
        }
        return true;
    }
}
```
2. DFS 
其实可以用colors数组来代替visited数组保存顶点是否访问信息，少创建一个变量
```java
class Solution {
    public boolean isBipartite(int[][] graph) {
        int v = graph.length;
        int[] colors = new int[v];
        boolean[] visited = new boolean[v];
        for(int i = 0; i < v; i++) {
            colors[i] = -1;
        }
        for(int i = 0; i < v; i++) {
            if(colors[i] == -1) {
                if(!dfs(i, graph, 0, colors)) {
                    return false;
                }
            }
        }
        return true;
    }
    private boolean dfs(int v, int[][] graph, int color, int[] colors) {
        colors[v] = color;
        for(int w: graph[v]) {
            if(colors[w] == -1) {
                if(!dfs(w, graph, 1 - color,colors)) {
                    return false;
                }
            } else if(colors[w] == colors[v]) {
                return false;
            }
        }
        return true;
    }
}

```


```
class Solution {

    private boolean[] visited;
    private int[] colors;
    private int[][] graph;

    public boolean isBipartite(int[][] graph) {
        this.graph = graph;
        int vertexCount = graph.length;
        visited = new boolean[vertexCount];
        colors = new int[vertexCount];
        for(int i=0;i<vertexCount;i++){
            if(!visited[i]){
                if(!dfs(i,0)) return false;
            }
        }
        return true;
    }

    private boolean dfs(int v, int color){
        visited[v] = true;
        colors[v] = color;
        for(int w:this.graph[v]){
            if(!visited[w]){
                if(!dfs(w,1-color)) return false;
            }
            else if(colors[w] == colors[v]) return false;
        }
        return true;
    }
}
```

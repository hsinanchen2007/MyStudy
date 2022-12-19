```
class Solution {
   private boolean[] visited;
    private int[] colors;
    private int[][] graph;

    public boolean isBipartite(int[][] graph) {

        this.visited = new boolean[graph.length];
        this.graph = graph;

        colors = new int[graph.length];

//        for (int v = 0; v < graph.length; v++) {
//            if (!visited[v]) {
//                if (!dfs(v, 0)) {
//                    return false;
//                }
//            }
//        }


        for (int v = 0; v < graph.length; v++) {
            if(!visited[v]){
                if(!dfs2(v)){
                    return false;
                }
            }
        }

//        for (int v = 0; v < graph.length; v++) {
//            if (!visited[v]) {
//                if (!bfs(v)) {
//                    return false;
//                }
//            }
//        }
        return true;
    }

    public boolean dfs(int v, int color) {
        visited[v] = true;
        colors[v] = color;
        for (int w : graph[v]) {
            if (!visited[w]) {
                if (!dfs(w, 1 - color)) {
                    return false;
                }
            } else if (colors[v] == colors[w]) {
                return false;
            }
        }
        return true;
    }

    public boolean dfs2(int v) {
        visited[v] = true;
        colors[v] = 0;
        Stack<Integer> stack = new Stack<>();
        stack.add(v);

        while(!stack.isEmpty()) {
            v = stack.pop();

            for (int w : graph[v]) {
                if(!visited[w]){
                    visited[w] = true;
                    stack.add(w);
                    colors[w] = 1 - colors[v];
                }else if(colors[v] == colors[w]){
                    return false;
                }
            }
        }

        return true;
    }

    public boolean bfs(int v) {
        visited[v] = true;
        colors[v] = 0;
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(v);

        while(!queue.isEmpty()){

            v = queue.poll();
            for (int w : graph[v]) {
                if(!visited[w]){
                    queue.offer(w);
                    visited[w] = true;
                    colors[w] = 1 - colors[v];
                } else if (colors[v] == colors[w]){
                    return false;
                }
            }
        }
        return true;
    }
}
```

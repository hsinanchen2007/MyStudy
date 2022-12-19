最最经典 回归自然的连通分量算法~
```
class Solution {
    private int count = 0;
    private boolean[] marked;
    private int[] id;
    private List<List> adj;
    public int countComponents(int n, int[][] edges) {
        adj = new ArrayList<>(n);
        for (int i = 0; i < n; i++){
            adj.add(i,new ArrayList<Integer>());
        }
        for (int[] x : edges){
            int v = x[0];
            int w = x[1];
            addEdge(v,w);
        }
        marked = new boolean[n];
        id = new int[n];
        for (int s = 0; s < n; s++){
            if (!marked[s]){
                dfs(adj.get(s), s);
                count++;
            }
        }
        return count;
    }
    private void addEdge(int v, int w){
        adj.get(v).add(w);
        adj.get(w).add(v);
    }
    private void dfs(List<Integer> twice,int v){
        marked[v] = true;
        id[v] = count;
        for (int w : twice){
            if (!marked[w])
                dfs(adj.get(w), w);
        }
    }
}
```


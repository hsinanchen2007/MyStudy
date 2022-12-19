```
class Solution {
    public boolean findWhetherExistsPath(int n, int[][] graph, int start, int target) {
        ArrayList<Integer>[] adj = new ArrayList[n];
        for (int i=0; i<n; i++) adj[i] = new ArrayList<>();
        for (int[] g: graph) adj[g[0]].add(g[1]);
        boolean[] vis = new boolean[n];
        return dfs(adj, vis, start, target);
    }

    boolean dfs(ArrayList<Integer>[] adj, boolean[] vis, int cur, int target) {
        if (cur == target) return true;
        vis[cur] = true;
        for (int nei: adj[cur]) {
            if (vis[nei]) continue;
            boolean ret = dfs(adj, vis, nei, target);
            if (ret) return true;
        }
        return false;
    }
}
```
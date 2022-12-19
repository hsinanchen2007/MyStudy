```
class Solution {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        // not shortest
        // bfs
        // bfs lost information about every route
        // dfs get every route
        int[][] g = graph;
        List<List<Integer>> r = new ArrayList<>();
        List<Integer> c = new ArrayList<>();
        c.add(0);
        dfs(c, r, g, 0);
        return r;
    }

    private void dfs(List<Integer> c, List<List<Integer>> r, int[][] g, int n) {
        if(n == g.length - 1) {
            r.add(new ArrayList<>(c));
            return;
        }

        int[] nbs = g[n];
        for(int nb : nbs) {
            c.add(nb);
            dfs(c, r, g, nb);
            c.remove(c.size() - 1);
        }
    }
}
```

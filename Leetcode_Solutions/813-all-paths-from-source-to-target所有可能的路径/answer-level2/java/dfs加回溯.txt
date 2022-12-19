![捕获.PNG](https://pic.leetcode-cn.com/298c6e1cff0bb271a723dfc3532e52db9159218de886d5c8b195d7bfb0e7941f-%E6%8D%95%E8%8E%B7.PNG)
个人觉得比官方答案好理解。
```
class Solution {
    boolean[] visited;
    List<List<Integer>> res;
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        int n = graph.length;
        visited = new boolean[n];
        res = new ArrayList<>();
        dfs(graph, new ArrayList<>(), 0);
        return res;
    }

    private void dfs(int[][] graph, List<Integer> path, int cur) {
        path.add(cur);        
        if (cur == graph.length-1) {
            res.add(new ArrayList<>(path));
            path.remove(path.size()-1);
            return;
        }
        visited[cur] = true;
        int[] pnts = graph[cur];
        for (int p: pnts)
            if (!visited[p]){
                dfs(graph, path, p);
            }
        visited[cur] = false;
        path.remove(path.size()-1);
    }
}
```
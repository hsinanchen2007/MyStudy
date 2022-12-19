**DFS**

深度优先的去遍历，假设分别有两个点的集合set1和set2,如果一条边的一个点在set1,另外一点一定在set2。DFS的时候需要不停的置换set1/set2。
```
class Solution {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        boolean[] visited = new boolean[n];
        Set<Integer> left = new HashSet<>();
        Set<Integer> right = new HashSet<>();
        for (int i = 0; i < graph.length; i++) {
            
            if (!visit(visited, i, graph, left, right)) {
                return false;
            }
        }
        return true;
    }
    
    
    boolean visit(boolean[] visited, int idx, int[][] graph, Set<Integer> left, Set<Integer> right) {
        if (visited[idx]) {
            return true;
        }
        visited[idx] = true;
        left.add(idx);
        int[] arr = graph[idx];
        for (int cur : arr) {
            if (left.contains(cur)) {
                return false;
            }
        }
       
        for (int next: arr) {
            if (!visit(visited, next, graph, right, left)) {
                return false;
            }
        }
        return true;
    }
}
```

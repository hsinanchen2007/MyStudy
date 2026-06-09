```
class Solution {
    /********************************
    Topological sorting
    **********************************/

    private final int VISITED = 2;
    private final int VISITING = 1;
    private final boolean CYCLE = false;
    private final boolean OK = true;

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        int n = numCourses;
        for (int[] arr : prerequisites) {
            int from = arr[1];
            List<Integer> to = map.getOrDefault(from, new ArrayList<>());
            to.add(arr[0]);
            map.put(from, to);
        }
        int[] visited = new int[n];
        for (int i : IntStream.range(0, n).boxed().collect(Collectors.toSet())) {
            boolean res = visit(i, visited, map);
            if (res == CYCLE) return false;
        }
        return true;
    }
    
    boolean visit(int cur, int[] visited,  Map<Integer, List<Integer>> map) {
        if (visited[cur] == VISITING) return CYCLE;
        if (visited[cur] == VISITED) return OK;
        visited[cur] = VISITING;
        for (int next: map.getOrDefault(cur, Collections.emptyList())) {
            boolean res = visit(next, visited, map);
            if (res == CYCLE) return CYCLE;
        }
        visited[cur] = VISITED;
        return OK;
    }
}
```

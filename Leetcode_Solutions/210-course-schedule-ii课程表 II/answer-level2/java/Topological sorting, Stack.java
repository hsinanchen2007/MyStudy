```
class Solution {
    private final int VISITED = 2;
    private final int VISITING = 1;
    private final boolean OK = true;
    private final boolean CYCLE = false;
    /********************************
    Topological sorting
    Stack
    *********************************/
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int n = numCourses;
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int[] arr : prerequisites) {
            List<Integer> nextList = map.getOrDefault(arr[1], new ArrayList<>());
            nextList.add(arr[0]);
            map.put(arr[1], nextList);
        }
        int[] visited = new int[n];
        Stack<Integer> stack = new Stack<>();
        for (int i: IntStream.range(0, n).boxed().collect(Collectors.toList())) {
            boolean res = visit(i, map, visited, stack);
            if (res == CYCLE) {
                return new int[0];
            }
        }
        int[] resArr = new int[stack.size()];
        int idx = 0;
        while (!stack.isEmpty()) {
            resArr[idx++] = stack.pop();
        }
        return resArr;
    }
    
    /**************dfs*********************/
    boolean visit(int cur, Map<Integer, List<Integer>> map, int[] visited, 
                 Stack<Integer> stack) {
        if (visited[cur] == VISITING) return CYCLE;
        if (visited[cur] == VISITED) return OK;
        visited[cur] = VISITING;
        for (int next: map.getOrDefault(cur, Collections.emptyList())) {
            boolean res = visit(next, map, visited, stack);
            if (res == CYCLE) {
                return CYCLE;
            }
        }
        
        visited[cur] = VISITED;
        stack.push(cur);
        return OK;
    }
}
```

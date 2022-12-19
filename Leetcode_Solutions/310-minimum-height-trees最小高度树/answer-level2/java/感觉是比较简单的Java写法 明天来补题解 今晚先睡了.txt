```
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> res = new LinkedList<>();
        if (n <= 2) {
            for (int i = 0; i < n; i ++) {
                res.add(i);
            }
            return res;
        }
        int[] Degree = new int[n];
        List<List<Integer>> adjacent = new ArrayList<>();

        for (int i = 0; i < n; i ++) {
            adjacent.add(new ArrayList<>());
        }

        for (int[] e : edges) {
            Degree[e[0]] += 1;
            Degree[e[1]] += 1;
            adjacent.get(e[0]).add(e[1]);
            adjacent.get(e[1]).add(e[0]);
        }

        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i ++) {
            if (Degree[i] == 1)
                queue.add(i);
        }
        
        while (n > 2) {
            int len = queue.size();
            n -= len;
            for (int i = 0; i < len; i ++) {
                int temp = queue.poll();
                for (int adj : adjacent.get(temp)) {
                    Degree[adj] -= 1;
                    if (Degree[adj] == 1)
                        queue.add(adj);
                }
            }
        }

        for (int q :queue) {
            res.add(q);
        }
        return res;
    }
}
```
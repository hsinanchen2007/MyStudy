```java
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> res = new ArrayList<>();
        if (n == 1) {
            res.add(0);
            return res;
        }

        int[] degrees = new int[n];
        List<List<Integer>> adjLists = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjLists.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            degrees[edge[0]]++;
            degrees[edge[1]]++;
            adjLists.get(edge[0]).add(edge[1]);
            adjLists.get(edge[1]).add(edge[0]);
        }

        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (degrees[i] == 1) {
                queue.offer(i);
            }
        }

        while (!queue.isEmpty()) {
            res.clear();
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int pre = queue.poll();
                res.add(pre);
                for (int cur : adjLists.get(pre)) {
                    if (--degrees[cur] == 1) {
                        queue.offer(cur);
                    }
                }
            }
        }
        return res;
    }
}
```

### 解题思路

思路是把可以到达的大节点，以及在大节点的时候我们还可以走多少步保存到一个map中，然后遍历所有edges， 在单条edge中可以到达的节点个数是这条edge的两个大节点可以走的步数之和和这条edge最多有多少个小节点的最小值。

1. 首先建立一个大节点和大节点之间有多少个小节点的map
2. 建立一个最大堆保存步数以及所在的大节点
3. seen中保存可以走到的大节点，以及剩余步数
4. 每次在堆中取最大步数以及其所在节点，然后遍历图，更新seen

### 代码

```java
class Solution {
    public int reachableNodes(int[][] edges, int M, int N) {
        Map<Integer, Map<Integer, Integer>> m = new HashMap<>();
        for (int[] edge : edges) {
            m.computeIfAbsent(edge[0], t -> new HashMap<>()).put(edge[1], edge[2]);
            m.computeIfAbsent(edge[1], t -> new HashMap<>()).put(edge[0], edge[2]);
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        pq.add(new int[]{M, 0});
        Map<Integer, Integer> seen = new HashMap<>();
        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            // step remain
            int step = top[0];
            // current node
            int node = top[1];
            if (!seen.containsKey(node)) {
                seen.put(node, step);
                if (m.containsKey(node)) {
                    for (int next : m.get(node).keySet()) {
                        // distance between current node and next node
                        int distance = m.get(node).get(next);
                        int left = step - distance - 1;
                        if (left >= 0 && m.containsKey(next)) {
                            pq.add(new int[]{left, next});
                        }
                    }
                }
            }
        }
        int res = seen.size();
        for (int[] edge : edges) {
            int a = seen.getOrDefault(edge[0], 0);
            int b = seen.getOrDefault(edge[1], 0);
            res += Math.min(a + b, edge[2]);
        }
        return res;
    }
}
```
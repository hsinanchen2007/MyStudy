```java
class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        Map<Integer, Map<Integer, Integer>> hm = new HashMap<>();
        for (int[] f : flights) {
            hm.computeIfAbsent(f[0], k -> new HashMap<>()).put(f[1], f[2]);
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> (a[0] - b[0]));
        pq.add(new int[]{0, src, K});
        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int price = top[0];
            src = top[1];
            int step = top[2];
            if (src == dst) return price;
            if (step >= 0) {
                Map<Integer, Integer> m = hm.getOrDefault(src, new HashMap<>());
                for (int k : m.keySet()) {
                    pq.add(new int[]{price + m.get(k), k, step - 1});
                }
            }
        }

        return -1;
    }
}
```
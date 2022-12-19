```java
class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        List<List<Integer>> l = new ArrayList<>();
        List<int[]> points = new ArrayList<>();
        // 对于某个building， 他的进入的高度是正的，出去的高度是负的
        for (int[] b : buildings) {
            
            points.add(new int[]{b[0], b[2]});
            points.add(new int[]{b[1], -b[2]});

        }
        // 所有building 先按照横坐标排序，然后按照高度排序
        Collections.sort(points, (a, b) -> {
            if (a[0] == b[0]) {
                return b[1] - a[1];
            }
            return a[0] - b[0];
        });

        Queue<Integer> pq = new PriorityQueue<Integer>((a, b) -> b - a);
        pq.offer(0);
        int preMax = 0;
        for (int[] p : points) {
            if (p[1] > 0) {
                pq.offer(p[1]);
            } else {
                pq.remove(-p[1]);
            }
            int cur = pq.peek();
            // 当高度发生变化时，把发生变化的点加入结果里面
            if (cur != preMax) {
                List<Integer> w =  new ArrayList<Integer>();
                w.add(p[0]);
                w.add(cur);
                l.add(w);
            }
            // 更新高度
            preMax = cur;
        }
        return l;
    }
}
```
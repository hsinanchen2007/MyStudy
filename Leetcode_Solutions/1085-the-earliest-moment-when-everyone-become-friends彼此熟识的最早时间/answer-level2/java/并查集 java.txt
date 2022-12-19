解题思路：

* 将logs按日期排序；
* 依赖遍历所有的log = logs[i]：
  * 执行find操作，如果两人属于同一个集合，说明已经认识了，不做任何操作；
  * 执行find操作，如果两人不属于同一个集合，说明还没有认识，执行union操作，max = log[0]。
  
* 返回更新的时间

``` java
class Solution {
    int[] parents;
    Map<Integer, Integer> times = new HashMap<>();

    int find(int i) {
        int p = parents[i];

        if (p != i) {
            parents[i] = find(p);
        }
        return parents[i];
    }

    public int earliestAcq(int[][] logs, int N) {
        parents = new int[N];
        for (int k = 0; k < N; k++) {
            parents[k] = k;
        }

        PriorityQueue<int[]> queue = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (int[] log : logs) {
            queue.offer(log);
        }

        int max = 0;
        while (!queue.isEmpty()) {
            int[] log = queue.poll();
            int l = find(log[1]);
            int r = find(log[2]);
            if (l != r) {
                parents[l] = r;
                max = log[0];
            }
        }

        for (int k = 1; k < parents.length; k++) {
            if (find(k) != find(0)) {
                return -1;
            }
        }

        return max;
    }
}
```
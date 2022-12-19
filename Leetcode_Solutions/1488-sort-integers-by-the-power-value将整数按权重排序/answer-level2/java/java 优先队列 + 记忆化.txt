### 思路
1. 看到第k个数，其实最简单的做法就是当成topK问题来处理，即一个时间复杂度为$O(nlogk)$的堆直接上。（题外话，理论上，若只是求第k小或第k大，快选才是最快的）；
2. 然后另一个关键的是求权重的过程。反正模拟就完事了。但是，我们会发现，题目给的是$[lo, hi]$，是一个区间，在计算权重的过程中会有很多重复的子问题。比如说我们10的权重相当于5的权重+1。因此，我们可以引入记忆化，也就说把计算过的值的权重记录下来，当下次计算权重的过程中可以快速返回。

```java
private Map<Integer, Integer> memo;

    private int getWeight(int num) {
        if (num == 1) {
            return 0;
        }

        if (memo.containsKey(num)) {
            return memo.get(num);
        }

        int count = (num & 1) == 0 ? getWeight(num >>> 1) : getWeight(3 * num + 1);
        count++;
        memo.put(num, count);
        return count;
    }

    public int getKth(int lo, int hi, int k) {
        // int[] = {值，权重}
        PriorityQueue<int[]> heap = new PriorityQueue<>((o1, o2) -> o1[1] == o2[1] ? o2[0] - o1[0] : o2[1] - o1[1]);
        memo = new HashMap<>();
        for (int i = lo; i <= hi; i++) {
            heap.offer(new int[]{i, getWeight(i)});
            if (heap.size() > k) {
                heap.poll();
            }
        }

        return heap.peek()[0];
    }
```
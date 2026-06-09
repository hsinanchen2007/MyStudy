最大表现=速度和(speeds) * 最低效率(minEfficiency)

由于speeds和minEfficiency都是根据选择的工程师变化而变化的，因此需要控制其中一个变量递减才能比较出结果最大值。

这里可以先对工程师按效率从大到小排序，然后根据这个顺序选择工程师同时计算表现值。
由于是根据效率从大到小排序的，因此计算表现值的效率只会小于或等于上次计算的表现值，而速度和可能大于或小于或等于上次表现值。
因此，通过这种选取方式，可以选出最大表现值。


```java
class Solution {
    public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
        Queue<int[]> engineerMaxEfficiencyHeap = new PriorityQueue<>((o1, o2) -> o2[1]- o1[1]);
        Queue<Integer> speedMinHeap = new PriorityQueue<>();
        for (int i = 0; i < n; ++i) {
            engineerMaxEfficiencyHeap.offer(new int[]{speed[i], efficiency[i]});
        }
        long speeds = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            int[] engineer = engineerMaxEfficiencyHeap.poll();
            speeds += engineer[0];
            speedMinHeap.offer(engineer[0]);
            speeds -= i >= k? speedMinHeap.poll() : 0;
            res = Math.max(res, speeds * engineer[1]);
        }
        return (int)(res % 1000000007);
    }
}
```

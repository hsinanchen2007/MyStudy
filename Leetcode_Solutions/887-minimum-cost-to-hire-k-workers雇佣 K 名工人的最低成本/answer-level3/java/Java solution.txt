```java
class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int K) {
        int n = quality.length;
        double[][] ratio = new double[n][2];
        for (int i = 0; i < n; i ++) {
            ratio[i] = new double[]{(double) wage[i] / quality[i], quality[i]};
        }
        Arrays.sort(ratio, (a, b) -> Double.compare(a[0], b[0]));
        PriorityQueue<Double> pq = new PriorityQueue<>();
        double sum = 0;
        double res = 999999999;
        for (int i = 0; i < n; i ++) {
            
            sum += ratio[i][1];
            pq.add(- ratio[i][1]);
            if (pq.size() > K) sum += pq.poll();
            if (pq.size() == K) res = Math.min(res,  ratio[i][0] * sum);
        }
        return res;
    }
}
```
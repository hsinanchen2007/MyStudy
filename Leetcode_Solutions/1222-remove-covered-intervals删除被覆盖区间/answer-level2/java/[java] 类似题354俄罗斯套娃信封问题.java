对于二维数组arr[][]的子数组a[]来说 , 升序排列a[0] 降序排列a[1] , 则只用考虑a[1]即可 , 若a[n - 1] >= a[n] 继续遍历 , a[n - 1] < a[n] 结果加一 .
```
    public int removeCoveredIntervals(int[][] intervals) {
        if (intervals.length <= 1) {
            return intervals.length;
        }
        Arrays.sort(intervals, (int[] a, int[] b) -> {
            if (a[0] == b[0]) {
                return b[1] - a[1];
            } else {
                return a[0] - b[0];
            }
        });
        int second = intervals[0][1];
        int res = 1;
        for (int i = 1; i < intervals.length; i++) {
            if (second < intervals[i][1]) {
                res++;
                second = intervals[i][1];
            }
        }
        return res;
    }
```

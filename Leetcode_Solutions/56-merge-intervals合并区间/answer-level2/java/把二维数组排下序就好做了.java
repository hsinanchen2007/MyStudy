```
public int[][] merge(int[][] intervals) {
        List<int[]> res = new ArrayList<>();

        //记录当前数组是否已经没用了
        boolean[] b = new boolean[intervals.length];

        Arrays.sort(intervals, Comparator.comparingInt((int[] a) -> a[0]));

        for (int i = 0; i < intervals.length; i++) {
            if (b[i]) continue;
            int l = intervals[i][0], r = intervals[i][1];
            for (int j = i + 1; j < intervals.length; j++) {
                if (b[j]) continue;
                int ll = intervals[j][0], rr = intervals[j][1];
                //两者相交
                if (!b[j] && (ll <= r && rr >= l)) {
                    //更新
                    l = Math.min(l, ll);
                    r = Math.max(r, rr);
                    b[j] = true;
                }
            }
            res.add(new int[]{l, r});
        }
        return res.toArray(new int[res.size()][2]);
    }
```

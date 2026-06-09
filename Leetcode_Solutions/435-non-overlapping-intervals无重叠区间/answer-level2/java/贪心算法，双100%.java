![捕获.PNG](https://pic.leetcode-cn.com/66e266c045ae83a40f0c883d9ca3c14b23425c9ec28821b7d574e2dabead0720-%E6%8D%95%E8%8E%B7.PNG)

```

class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals.length == 0) return 0;
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0] != o2[0])
                    return o1[0] - o2[0];
                else return o1[1] - o2[1];
            }
        });
        int ed = intervals[0][1];
        int cnt = 0;
        for (int i=1; i<intervals.length; i++) {
            int[] interval = intervals[i];
            if (interval[0] < ed) {
                cnt++;
                ed = Math.min(ed, interval[1]);
            } else ed = interval[1];
        }
        return cnt;
    }
}

```

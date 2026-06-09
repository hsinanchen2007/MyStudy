
```
import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        int len = intervals.length;
        if(intervals == null || len < 2) return 0;
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[1] - o2[1];
            }
        });
        int count = 1, curEnd = intervals[0][1];
        for(int i = 1; i < len; i++){
            if(intervals[i][0] >= curEnd){
                count++;
                curEnd = intervals[i][1];
            }
        }
        return len - count;
    }
}
```

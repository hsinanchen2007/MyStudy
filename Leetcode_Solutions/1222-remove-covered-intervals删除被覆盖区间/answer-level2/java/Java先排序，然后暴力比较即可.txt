```java
//代码有待优化
import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        if(intervals.length  == 1){
            return 1;
        }
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] x, int[] y) {
                return x[0] - y[0] == 0 ? x[1] - y[1] : x[0] - y[0];
            }
        });
        int len = intervals.length;

        for(int i = 1; i < intervals.length; i++){
            for(int j = i - 1; j >= 0; j--){
                if(intervals[i][1] <= intervals[j][1]){
                    len --;
                    break;
                }
            }

        }

        return len;
    }
}
```

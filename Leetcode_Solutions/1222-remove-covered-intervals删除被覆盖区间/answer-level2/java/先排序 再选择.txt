### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0]-o2[0];
            }
        });
        int[] sum = new int[intervals.length];
        for (int i = 0; i < intervals.length; i++) {
            for(int j = i+1;j < intervals.length;j++){
                if (sum[j] != 1){
                    if (intervals[j][0] < intervals[i][1]){
                        if (intervals[j][1] <= intervals[i][1])
                            sum[j] = 1;
                    }
                    else
                        break;
                }
            }
        }
        int res = 0;
        for (int i : sum) {
            if (i == 0)
                res++;
        }
        return res;
    }
}
```
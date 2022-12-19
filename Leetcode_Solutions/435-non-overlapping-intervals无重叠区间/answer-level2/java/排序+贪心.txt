### 解题思路
首先对所有的区间按照左端点位置进行排序，此后对于每一个区间，如果其左端点大于等于上一个区间的右端点，则不需要进行移除，如果其左端点小于上一个区间的右端点，则需要移除一个区间。
考虑尽可能少的移除区间数量，我们希望移除后剩余区间的右端点值尽可能地小。因此，若当前区间的右端点大于上一区间的右端点，则移除当前区间，反之则移除上一区间。

### 代码

```java
class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        if(intervals == null || intervals.length < 2) {
            return 0;
        }
        Arrays.sort(intervals, new Comparator<int[]>() {
            public int compare(int[] interval1, int[] interval2) {
                return interval1[0] == interval2[0] ? interval1[1] - interval2[1] : interval1[0] - interval2[0];
            }
        });
        int nowRight = intervals[0][1];
        int rmCnt = 0;
        for(int i = 1; i < intervals.length; i++) {
            if(intervals[i][0] >= nowRight) {
                nowRight = intervals[i][1];
            }
            else {  // intervals[i][0] < nowRight, need remove
                nowRight = Math.min(intervals[i][1], nowRight);
                rmCnt++;
            }
        }
        return rmCnt;
    }
}
```
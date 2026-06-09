参考1109.航班预定统计

```java
class Solution {
    public int minMeetingRooms(int[][] intervals) {
        int n = 0;
        for (int[] interval : intervals) {
            n = Math.max(n, interval[1]);
        }
        int[] variance = new int[n + 1];
        for (int[] interval : intervals) {
            variance[interval[0]]++;
            variance[interval[1]]--;
        }
        int max = 0;
        int pre = 0;
        for (int i = 0; i < n; i++) {
            pre = pre + variance[i];
            max = Math.max(max, pre);
        }
        return max;
    }
}```
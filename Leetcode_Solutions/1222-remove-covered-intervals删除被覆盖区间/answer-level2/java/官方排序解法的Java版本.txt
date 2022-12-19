class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        // (o1, o2) -> 是自定义Comparator
        Arrays.sort(intervals, (o1, o2) -> o1[0] == o2[0] ? o2[1] - o1[1] : o1[0] - o2[0]);
        int count = intervals.length, res = count;
        // intervals[0][1] 即是目前的最小值（以及经过排序）
        int max = intervals[0][1];
        // 从intervals[1][1]开始
        for (int i = 1; i < count; i++) {
            // 可以这个区间会被覆盖
            if (intervals[i][1] <= max) {
                res--;
            } else {
                //更新一下最大值
                max = Math.max(max, intervals[i][1]);
            }
        }
        return res;
    }
}
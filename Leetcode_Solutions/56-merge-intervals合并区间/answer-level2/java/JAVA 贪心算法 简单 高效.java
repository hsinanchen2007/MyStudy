```
class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals == null || intervals.length == 0
                || intervals[0] == null || intervals[0].length != 2) {
            return new int[0][];
        }
        List<int[]> result = new ArrayList<>();
        Arrays.sort(intervals, Comparator.comparingInt(e -> e[0]));
        int[] next = new int[]{intervals[0][0], intervals[0][1]};
        result.add(next);
        for (int i = 1; i < intervals.length; i++) {
            if (next[1] >= intervals[i][0]) {
                if (next[1] < intervals[i][1]) {
                    next[1] = intervals[i][1];
                }
            } else {
                next = new int[]{intervals[i][0], intervals[i][1]};
                result.add(next);
            }
        }
        return result.toArray(new int[0][]);
    }
}
```

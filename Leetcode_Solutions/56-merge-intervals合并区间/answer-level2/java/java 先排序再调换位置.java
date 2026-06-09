```
    public int[][] merge(int[][] intervals) {
        if (intervals.length <= 1) {
            return intervals;
        }
        //先进行排序
        for (int i = 0; i < intervals.length; i++) {
            int minIndex = i;
            int min = Integer.MAX_VALUE;
            for (int j = i; j < intervals.length; j++) {
                if (intervals[i][0] > intervals[j][0] && min > intervals[j][0]) {
                    min = intervals[j][0];
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                int[] temp = intervals[i];
                intervals[i] = intervals[minIndex];
                intervals[minIndex] = temp;
            }
        }
        //排序好进行替换
        int current = 0;
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[current][1] >= intervals[i][0]) {
                if (intervals[current][1] < intervals[i][1]) {
                    intervals[current][1] = intervals[i][1];
                }
            } else {
                current++;
                intervals[current][0] = intervals[i][0];
                intervals[current][1] = intervals[i][1];
            }
        }
        return Arrays.copyOfRange(intervals, 0, ++current);
    }
```

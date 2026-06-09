思路：对原始数组里的每一个区间进行遍历，判断和新插入区间内的关系，如果在新区间前面，则直接插入；如果在新区间内部则跳过这个区间；否则的话，说明两个区间相交，如果两个区间相交，则有三种情况：
1. 新插入区间，在当前区间之前，那么先add新区间，之后再add当前区间；
2. 当前区间的right == 新区间的left，那么add new int[]{newInterval[0], interval[1]}
3. 否则的话，add一个 new int[]{Math.min(interval[0], newInterval[0]), Math.max(interval[1], newInterval[1])}，即相交情况。
同时在这步操作结束后，需要取answer的最后一个区间，替换原来的newInterval区间，并弹出最后一个区间。

遍历结束时，需要再add newIntereval。

完整代码如下：
```
public int[][] insert(int[][] intervals, int[] newInterval) {
        if (intervals.length == 0) {
            return new int[][]{newInterval};
        }
        List<int[]> ans = new ArrayList<>();
        for (int i = 0; i < intervals.length; i++) {
            int[] interval = intervals[i];
            if (interval[1] < newInterval[0]) {
                ans.add(interval);
            } else if (interval[0] >= newInterval[0] && interval[1] <= newInterval[1]) {
                continue;
            } else {
                if (interval[0] > newInterval[1]) {
                    ans.add(newInterval);
                    ans.add(interval);
                } else if (interval[0] == newInterval[1]) {
                    ans.add(new int[]{newInterval[0], interval[1]});
                } else {
                    ans.add(new int[]{Math.min(interval[0], newInterval[0]), Math.max(interval[1], newInterval[1])});
                }
                newInterval = ans.get(ans.size() - 1);
                ans.remove(ans.size() - 1);
            }
        }
        ans.add(newInterval);
        return ans.toArray(new int[ans.size()][2]);
    }
```
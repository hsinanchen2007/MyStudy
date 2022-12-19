代码如下：

```
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> res = new ArrayList<>();
        //如果已经解决了冲突，就不用再解决一遍，简单的逻辑优化
        boolean processed = false;
        for (int i = 0; i < intervals.length;) {
            if (processed) {
                res.add(intervals[i]);
                i++;
            } else {
                //如果新的分区在当前遍历分区的左边，那么需要把新分区加进来，此时没有重合
                if (newInterval[1] < intervals[i][0]) {
                    res.add(newInterval);
                    processed = true;
                } else if (newInterval[0] > intervals[i][1]) {
                //如果新的分区在当前分区的右边，则把当前分区加进来，此时没有重合
                    res.add(intervals[i]);
                    i++;
                } else {
                //存在重合，往后寻找直到找到第一个与它不重合的分区
                //所有重合分区的左边界就是第一个分区和新分区的左边界偏小值
                    int left = Math.min(newInterval[0], intervals[i][0]);
                    while (i < intervals.length && intervals[i][0] <= newInterval[1]) {
                        i++;
                    }
                //所有重合分区的右边界就是最后一个分区和新分区的右边界偏小值
                    int right = Math.max(intervals[i - 1][1], newInterval[1]);
                    res.add(new int[]{left, right});
                    processed = true;
                }
            }
        }
        //如果一直没处理，那么证明这个分区在之前所有分区之后，直接加进来
        if (!processed) {
            res.add(newInterval);
        }
        return res.toArray(new int[0][]);
    }
```

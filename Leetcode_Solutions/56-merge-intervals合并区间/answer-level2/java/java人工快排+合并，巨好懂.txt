```

    public int[][] merge(int[][] intervals) {

        if (intervals.length == 0) return new int[0][0];

        List<int[]> res = new ArrayList<>();

        // 先按每个一维数组的首元素进行快排。
        sortIntervals(intervals, 0, intervals.length-1);

        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] <= end) {
                // 发生合并，更新窗口的end
                end = Math.max(intervals[i][1], end);
            } else {
                // 无法合并，需要把上一个窗口添加到结果集再重置窗口为当前数组
                int[] item = new int[2];
                item[0] = start;
                item[1] = end;
                res.add(item);
                // 重置start和end
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        // 遍历完成，添加上一个窗口。
        int[] item = new int[2];
        item[0] = start;
        item[1] = end;
        res.add(item);

        int[][] result = new int[res.size()][];
        for (int i = 0; i < res.size(); i++) {
            result[i] = res.get(i);
        }

        return result;

    }


    // 快排实现
    private void sortIntervals(int[][] intervals, int left, int right) {
        if (left >= right) return;
        int tmp = left; // 记录被挖的坑在哪
        int[] pivot = intervals[tmp]; // 挖坑填数，这里是最原始的坑上的数组。
        int l = left;
        int r= right;
        while (l != r) {
            while (r > l && intervals[r][0] >= pivot[0]) {
                r--;
            }
            intervals[tmp] = intervals[r];
            tmp = r;

            if (l == r) break;

            while (l < r && intervals[l][0] <= pivot[0]) {
                l++;
            }
            intervals[tmp] = intervals[l];
            tmp = l;
        }
        intervals[l] = pivot;
        sortIntervals(intervals, left, l);
        sortIntervals(intervals, l+1, right);
    }
```

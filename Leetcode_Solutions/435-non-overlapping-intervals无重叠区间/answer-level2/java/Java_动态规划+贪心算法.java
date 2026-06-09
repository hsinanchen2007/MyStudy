## 动态规划解法
```java
    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals.length == 0) {
            return 0;
        }
        Arrays.sort(intervals, (o1, o2) -> {
            if (o1[0] != o2[0]) {
                if (o1[0] < o2[0]) {
                    return -1;
                } else {
                    return 1;
                }
            } else {
                return Integer.compare(o1[1], o2[1]);
            }
        });
        // dp[i] 表示取[0,i]时，最大的不重叠区间
        // dp[1]=1
        int[] dp = new int[intervals.length];
        Arrays.fill(dp, 1);
        for (int i = 1; i < intervals.length; i++) {
            // 跟i前面的区间组合
            for (int j = 0; j < i; j++) {
                if (intervals[j][1] <= intervals[i][0]) {
                    // 动态规划
                    dp[i] = Math.max(dp[i], 1 + dp[j]);
                }
            }
        }
        // 找出最大值
        int result = 0;
        for (int i = 0; i < dp.length; i++) {
            result = Math.max(result, dp[i]);
        }
        // 答案是要去除多少个
        return intervals.length - result;
    }
```

## 贪心算法
```java
    // 贪心算法
    // 按照区间的结尾排序，每次选择结尾最早的，且和前一个区间不重叠的区间。
    // 因为每次都选结尾最早的，所以区间跨度一定是最小的，重叠就最少
    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals == null || intervals.length == 0) {
            return 0;
        }
        Arrays.sort(intervals, (o1, o2) -> {
            if (o1[1] != o2[1]) {
                if (o1[1] < o2[1]) {
                    return -1;
                } else {
                    return 1;
                }
            } else {
                if (o1[0] < o2[0]) {
                    return -1;
                } else if (o1[0] == o2[0]) {
                    return 0;
                } else {
                    return -1;
                }
            }
        });
        int result = 1;
        // 上一个合法的区间
        int pre = 0;
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] >= intervals[pre][1]) {
                pre = i;
                result++;
            }
        }
        return intervals.length - result;
    }
```

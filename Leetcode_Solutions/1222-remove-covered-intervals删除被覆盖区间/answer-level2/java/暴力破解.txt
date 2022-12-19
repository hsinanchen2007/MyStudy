# 思路
遍历每个区间，拿当前区间与其他区间进行比较，看是否被其它区间覆盖，如覆盖，区间数减1。等全部遍历完，剩下的区间数就是答案。具体代码如下：

```java
    public int removeCoveredIntervals(int[][] intervals) {
        int len = intervals.length;
        int ans = len;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (i == j) {
                    continue;
                }
                if (intervals[j][0] <= intervals[i][0] && intervals[j][1] >= intervals[i][1]) {
                    ans--;
                    break;
                }
            }
        }

        return ans;
    }

```

# 复杂度
**时间复杂度**: $O(n^2)$
**空间复杂度**: $O(1)$
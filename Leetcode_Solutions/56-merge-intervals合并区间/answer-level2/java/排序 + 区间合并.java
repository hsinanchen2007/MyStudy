### 解题思路
按照 start 对区间集合排序后，合并区间集合
1. 排序撸了个快排，也可直接实现  Comparator<Integer>
2. 合并区间集合的过程需要考虑各种 corner case
```
[1,3][2,4]
[1,4][2,3]
[1,3][1,4]
[1,4][4,5]
```

### 代码

```java
class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals == null || intervals.length <= 1) return intervals;
        quickSort(intervals, 0, intervals.length - 1);

        int k = 0;
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[k][0] == intervals[i][0] || intervals[k][1] >= intervals[i][0]) {
                intervals[k][1] = intervals[i][1] < intervals[k][1] ? intervals[k][1] : intervals[i][1];
            } else if (intervals[k][0] <= intervals[i][0] && intervals[k][1] >= intervals[i][1]) {
                continue;
            } else {
                intervals[++k] = intervals[i];
            }
        }

        int ans[][] = new int[k+1][2];
        for (int i = 0; i <= k; i++) {
            ans[i]= intervals[i];
        }
        
        return ans;
    }

    public void quickSort(int[][] a, int start, int end) {
        if (start >= end) return;
        int[] sentinel = a[start];
        int i = start, j = end;
        while (i < j) {
            while (i < j && a[j][0] > sentinel[0]) {
                j--;
            }

            if (i < j) {
                a[i] = a[j];
                i++;
            }

            while (i < j && a[i][0] < sentinel[0]) {
                i++;
            }

            if (i < j) {
                a[j] = a[i];
                j--;
            }
        }
        a[i] = sentinel;
        quickSort(a, start, i - 1);
        quickSort(a, i + 1, end);
    }
}
```
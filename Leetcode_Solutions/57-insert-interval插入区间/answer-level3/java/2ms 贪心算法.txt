### 解题思路
以intervals[[1,2],[3,5],[7,8]]，newInterval[4,6]为例。
intervals[0][1]<newInterval[0],result添加intervals[0];
intervals[1][0]<newInterval[0],改变newInterval的值为[3,6]（既当intervals中的区间和newInterval有重合时，改变newInterval的值，此区间也不会添加到result中）;
intervals[2][0]>newInterval[1],result添加newInterval和Interval[1]。
### 代码

```java
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        if (newInterval == null || intervals == null) {
            return intervals;
        }
        if (intervals.length == 0) return new int[][]{newInterval};

        List<int[]> result = new LinkedList<>();
        int i = 0;
        if (intervals[0][0] > newInterval[1]) {
            result.add(newInterval);
        }
        else if (intervals[intervals.length - 1][1] >= newInterval[0]) {
            for (; i < intervals.length; i++) {
                int[] interval = intervals[i];
                if (interval[1] < newInterval[0]) {
                    result.add(interval);
                    continue;
                }
                if (interval[0] > newInterval[1]) {
                    result.add(newInterval);
                    result.add(interval);
                    i++;
                    break;
                }
                newInterval[0] = Math.min(interval[0], newInterval[0]);
                newInterval[1] = Math.max(interval[1], newInterval[1]);
            }
        }
        for (; i < intervals.length; i++) {
            result.add(intervals[i]);
        }
        // 当newInterval与intervals内所有区间都有重合时，result为空
        if (result.isEmpty() || result.get(result.size() - 1)[1] < newInterval[0]) {
            result.add(newInterval);
        }        
        return result.toArray(new int[0][0]);
    }
}
```
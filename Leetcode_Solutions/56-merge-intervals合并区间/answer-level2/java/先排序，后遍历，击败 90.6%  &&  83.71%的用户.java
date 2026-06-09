### 解题思路
count记录合并的次数，并存入原数组，最终用Arrays.copyOf()截取需要的长度即可。

### 代码

```java
class Solution {
    public int[][] merge(int[][] intervals) {
        int len = intervals.length;
        if (len == 0 || intervals == null) return new int[][]{};
        Arrays.sort(intervals, (int[] a, int[] b) -> a[0] - b[0]);
        int count = 0;
        for (int i = 1; i < len; i++) {
        	if (intervals[count][1] < intervals[i][0]) {
        		intervals[++count] = intervals[i];	
        	}
        	else {
                intervals[count][1] = Math.max(intervals[i][1], intervals[count][1]);
        	}
        }
        return Arrays.copyOf(intervals, count + 1);		
    }
}
```
### 解题思路
![图片.png](https://pic.leetcode-cn.com/b5935a5ace37d457a1293c574f325f3f19de7ea578d37b92cb86267002e9000d-%E5%9B%BE%E7%89%87.png)

### 代码

```java
class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals == null || intervals.length == 0) return 0;
        Arrays.sort(intervals, (o1, o2) -> {
            if (o1[0] == o2[0]) {
                return o1[1] - o2[1];
            }
            return o1[0] - o2[0];
        });
        int[] pre = intervals[0];
        int count = 0;
        for (int i = 1; i < intervals.length; i++) {
            int[] cur = intervals[i];
            if (cur[0] < pre[1]) {
                count ++;
                if (cur[1] < pre[1]) {
                    pre = cur;
                }
            } else {
                pre = cur;
            }
        }

        return count;
    }
}
```
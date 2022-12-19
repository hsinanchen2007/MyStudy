今天的面试题（2019-10-14），现场写出来的算法，回来试了一下，算法没问题，一次通过。（实际面试的题目是老版本题目）

大致思路是，遍历所有区间，查找其中是否有拓展了新区间（区间存在交叉覆盖），并更新区间的开始结束位置。如果没有交叉则原样保留。需要注意一些细节：
1. 判断是否拓展开始位置与是否拓展结束位置，是并行的，不能使用 if-else，可能存在新区间完整包含在旧区间范围内的情况，即拓展了新区间的开始位置，也拓展了结束位置。
2. 需要一个参数记录是否已经添加过新区间，防止多次添加新区间。遍历结束后如果尚未添加新区间，要进行添加，以处理新区间完整位于原区间后方的情况。

本算法还可以做一定优化，但达不到优化复杂度的级别。比如：与新区间不相交的情况，可以放到前面，符合时直接 continue，避免了拓展了新区间的判断。

> Runtime: 1 ms, faster than 99.11% of Java online submissions. 
> Memory Usage: 41.7 MB, less than 68.75% of Java online submissions.

```java
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> ret = new ArrayList<int[]>();
        int start = newInterval[0], end = newInterval[1];
        boolean added = false;

        for(int[] interval : intervals) {
            // 拓展了新区间的开始位置
            if (interval[0] <= newInterval[0] && newInterval[0] <= interval[1]) {
                start = interval[0];
            }
            // 拓展了新区间的结束位置
            if (interval[0] <= newInterval[1] && newInterval[1] <= interval[1]) {
                end = interval[1];
            }

            // 在新区间前方，与新区间不相交
            if (interval[1] < newInterval[0]) {
                ret.add(interval);
            // 在新区间后方，与新区间不相交，第一次达到新区间后方时需要插入新区间
            } else if (newInterval[1] < interval[0]) {
                if (!added) {
                    ret.add(new int[]{start, end});
                    added = true;
                }

                ret.add(interval);
            }

            // 其他情况（老区间被新区间包含的情况），忽略
        }

        // 如果新区间没有插入，要手动插入（新区间就是最后方的区间的情况）
        if (!added) {
            ret.add(new int[]{start, end});
        }
        return ret.toArray(new int[ret.size()][2]);
    }
}    
```

**其他**：
因为题目给出的区间是不重叠的，因此我们可以知道包含一个值的范围只可能是零个或一个。因此，还有一种想法是，直接二分查找是否有包含新区间开始/结束的区间，就能直接得到新区间的最终范围。这样，所有不重叠的区间加上这个最终区间，就是答案。

不过，最差复杂度仍然是 O(n)，仅提供一种思路。

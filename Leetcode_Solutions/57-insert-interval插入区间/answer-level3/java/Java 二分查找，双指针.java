贪心是思想，二分和双指针是手段
**1.两次二分查找。**时间O(lgn)，空间O(1)
确定新区间要合并或插入到的开始索引`start`和结束索引`end`
**2.双指针遍历。**时间O(n)，空间O(1)
将start之前的区间原样插入结果数组，再将start到end之间的区间合并插入结果数组，再将end之后的区间原样插入结果数组

总时间复杂度O(n)
总空间复杂度O(1)
```
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int start, end;
        int low = 0, high = intervals.length;
        while (low < high) {
            int mid = (low + high) >>> 1;
            if (intervals[mid][1] >= newInterval[0]) high = mid;
            else low = mid + 1;
        }
        start = low;
        high = intervals.length;
        while (low < high) {
            int mid = (low + high) >>> 1;
            if (intervals[mid][0] > newInterval[1]) high = mid;
            else low = mid + 1;
        }
        end = low;
        // 至此，如果start != end，则intervals[start...end-1]为原数组中需要合并的部分
        // 如果start == end，则需要将newInterval插入原数组的start位置，后面的元素依次后移
        // start == end时，也有可能是在intervals.length位置
        int[][] res = new int[intervals.length - end + start + 1][2];
        for (int i = 0, j = 0; j < res.length; i++, j++) {
            if (start == i) {
                if (i == end) {
                    res[start][0] = newInterval[0];
                    res[start][1] = newInterval[1];
                    if (start < intervals.length) {
                    	res[start + 1][0] = intervals[start][0];
                        res[start + 1][1] = intervals[start][1];
                    }
                    j++;
                } else {
                    res[start][0] = Math.min(newInterval[0], intervals[start][0]);
                    res[start][1] = Math.max(newInterval[1], intervals[end - 1][1]);
                    i = end - 1;
                }
                continue;
            }
            res[j][0] = intervals[i][0];
            res[j][1] = intervals[i][1];
        }
        return res;
    }
}
```

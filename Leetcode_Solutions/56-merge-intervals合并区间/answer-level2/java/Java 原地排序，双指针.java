**1.手撕快排**。时间O(nlgn)，空间O(1)
将数组按照每个区间的左端点值升序排列。
**2.双指针`i`和`j`**。时间O(n)，空间O(1)
`j`用于保持，`i`用于探索。前进策略包含两种情况：
（1）第`i`个区间的左端点值小于等于第`j`个区间的右端点值，则可以合并；
（2）第`i`个区间的左端点值大于第`j`个区间的右端点值，则不可以合并，结果中需要新加入这个区间。
**3.构造输出**。
用于保持的`j`指针所在位置就是最终结果需要从头截取到的位置。
**4.特判**
数组为空时，返回空数组

总时间复杂度O(nlgn)
总空间复杂度O(1)
```
class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals == null || intervals.length == 0) return new int[0][0];
        quickSort(intervals, 0, intervals.length - 1);
        int j = 0;
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] <= intervals[j][1]) {
                intervals[j][1] = Math.max(intervals[i][1], intervals[j][1]);
            } else {
                j++;
                intervals[j][0] = intervals[i][0];
                intervals[j][1] = intervals[i][1];
            }
        }
        return Arrays.copyOf(intervals, j + 1);
    }

    private void quickSort(int[][] arr, int start, int end) {
        if (start >= end) {
            return;
        }
        int left = start, right = end;
        int pivot = arr[start][0];
        while (left < right) {
            while (arr[right][0] >= pivot && left < right) right--;
            while (arr[left][0] <= pivot && left < right) left++;
            if (left < right) {
                int[] tmp = arr[right];
                arr[right] = arr[left];
                arr[left] = tmp;
            }
        }
        int[] tmp = arr[right];
        arr[right] = arr[start];
        arr[start] = tmp;
        quickSort(arr, start, right - 1);
        quickSort(arr, right + 1, end);
    }
}
```

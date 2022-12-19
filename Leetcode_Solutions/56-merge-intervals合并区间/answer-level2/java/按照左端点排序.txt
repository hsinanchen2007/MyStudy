### 解题思路
按照左端点的值进行排序，分别以left和right记录当前生成区间的左右端点。
如果新的区间的左端点小于right，则可以进行合并，更新right的值；
如果新的区间的左端点大于right，则不可以合并，将当前区间写入列表，更新left和right。

### 代码

```java
class Solution {
    public int[][] merge(int[][] intervals) {
        if(intervals == null || intervals.length < 1) {
            return new int[0][0];
        }
        ArrayList<int[]> list = new ArrayList<int[]>();
        Arrays.sort(intervals, new Comparator<int[]>() {
            public int compare(int[] interval1, int[] interval2) {
                return interval1[0] - interval2[0];
            }
        });
        int left = intervals[0][0];
        int right = intervals[0][1];
        for(int i = 1; i < intervals.length; i++) {
            if(intervals[i][0] <= right) {
                right = Math.max(right, intervals[i][1]);
            }
            else {
                list.add(new int[] {left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        if(list.size() == 0 || list.get(list.size() - 1)[0] != left) {
            list.add(new int[] {left, right});
        }
        int[][] arr = new int[list.size()][];
        for(int i = 0; i < list.size(); i++) {
            arr[i] = list.get(i);
        }
        return arr;
    }
}
```
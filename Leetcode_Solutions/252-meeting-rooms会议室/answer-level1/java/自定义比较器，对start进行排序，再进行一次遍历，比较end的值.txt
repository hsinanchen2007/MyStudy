自定义比较器，对start进行排序，再进行一次遍历，比较end的值

### 代码

```java
class Solution {
       public boolean canAttendMeetings(int[][] intervals) {

        Arrays.sort(intervals, new SortClass());

        for (int i = 0; i < intervals.length - 1; i++) {
            if (intervals[i][1] > intervals[i + 1][0]) {
                return false;
            }
        }
        return true;
    }

    private class SortClass implements Comparator<int[]> {// 二维数组排序，泛型是一维数组  todo

        @Override
        public int compare(int[] m1, int[] m2) {
            return m1[0] - m2[0];
        }
    }
}
```
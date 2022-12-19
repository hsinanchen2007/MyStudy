### 解题思路
很愚蠢的投影法，就是把每个区间映射到一个数组上，然后遍历一边数组取出连续的区间就可以了，作两次遍历，理论上最小应该是O(n)的复杂度，但是因为测试数据好诡异加了好多条件判断就慢了

### 代码

```java
class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals.length == 0) return new int[][]{};
        int maxNum = Integer.MIN_VALUE;
        for (int i = 0; i < intervals.length; i++) {
            for (int j = 0; j < 2; j++) {
                intervals[i][j] *= 2;
                if (maxNum < intervals[i][j]) {
                    maxNum = intervals[i][j];
                }
            }
        }
        int[] temp = new int[maxNum + 1];
        for (int i = 0; i < intervals.length; i++) {
            if (intervals[i][0] == intervals[i][1] && temp[intervals[i][0]] != 1) {
                    temp[intervals[i][0]] = 2;
                    continue;
            }
            for (int j = intervals[i][0]; j <= intervals[i][1]; j++) {
                temp[j] = 1;
            }
        }
        List<int[]> l = new ArrayList<>();
        for (int i = 0; i <= maxNum; i++) {
            if (temp[i] == 1) {
                int left = i, right = i;
                while (i <= maxNum && temp[i] == 1) i++;
                right = --i;
                int[] a = new int[2];
                a[0] = left / 2;
                a[1] = right / 2;
                l.add(a);
            } else if (temp[i] == 2) {
                int[] a = new int[2];
                a[0] = i / 2;
                a[1] = i / 2;
                l.add(a);
            } 
        }
        return (int[][]) l.toArray(new int[0][]);
    }
}
```
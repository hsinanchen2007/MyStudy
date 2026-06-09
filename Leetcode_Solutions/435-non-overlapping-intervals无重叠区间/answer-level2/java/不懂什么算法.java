### 解题思路
不懂什么算法，从题目入手。分析题目要移除最少，那就要尽可能移除间隔大的；
1、排序，先按照end排序，如果end相同则按照start排序，把start小的往后放
2、判断当前与前一个是否有交集，如果有交集则把当前值设置为前一个
### 代码

```java
class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals.length == 0) {
            return 0;
        }
        if (intervals[0].length == 0) {
            return 0;
        }
        //先按照右边界排序，大的往后放，右边界相同左边界小的靠后
        //要移除数量小，需要把重叠的且右边界大的移除
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] t1, int[] t2) {
                return t2[1] == t1[1] ? t2[0] - t1[0] : t1[1] - t2[1];
            }           
        });
        int ans = 0;
        for (int i = 1; i < intervals.length; i++) {
            //如果后一个的left大于等于当前right，continue
            if (intervals[i][0] >= intervals[i-1][1]) {
                continue;
            } else {
            //如果后一个和当前有交集，则把当前变成前一个
                intervals[i] = intervals[i-1];
                ans++;
            }
        } 
        return ans;
    }
}
```
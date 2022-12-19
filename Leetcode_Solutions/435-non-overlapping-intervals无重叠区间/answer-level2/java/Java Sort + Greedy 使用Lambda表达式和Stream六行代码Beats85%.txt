思路: 
    采用贪心算法, 先按照右区间边界排序, 之后从前向后判断即可. 代码采用了Lambda所以看起来比较简洁.

```java
    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals == null || intervals.length <= 1) return 0;

        Arrays.sort(intervals, (x, y) -> x[1] - y[1]);

        int bound = intervals[0][1], res = 0;
        for (int i = 1; i < intervals.length; ++i) {
            if (intervals[i][0] < bound) res++;
            else bound = intervals[i][1];
        }

        return res;
    }
```

下面是一个使用Lambda和Stream的方法, 因为Java中匿名内部类和局部内部类只能访问final局部变量, 所以将bound和res定义为了成员变量即可!

```java
class Solution {
    
    private int bound;

    private int res;

    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals == null || intervals.length <= 1) return 0;

        Arrays.sort(intervals, (x, y) -> x[1] - y[1]);

        bound = intervals[0][1];
        res = 0;
        Arrays.stream(intervals).skip(1).forEach(x -> {
            if(x[0] < bound) res++;
            else bound = x[1];
        });

        return res;
    }
}

```

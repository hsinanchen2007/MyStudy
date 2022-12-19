### 解题思路
代码主要分为一下几个部分：
1.处理原数组为空时的情况
2.将较小的无需调整的数组放入list
3.开始构建数组，寻找起始值start
4.寻找end
5.将剩余的数组放入list
### 代码

```java
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        // corner case
        if (intervals.length == 0) return new int[][]{newInterval};
        //pre
        List<int[]> ans = new ArrayList<>();
        int p = 0;
        while(p < intervals.length){
            if (newInterval[0] <= intervals[p][1]){
                break;
            }
            ans.add(intervals[p++]);
        }
        // start
        int start;
        if (p < intervals.length && newInterval[0] > intervals[p][0]){
            start = intervals[p][0];
        }
        else start = newInterval[0];

        while(p < intervals.length){
            if (newInterval[1] <= intervals[p][1]){
                break;
            }
            p++;
        }
        // end
        if (p >= intervals.length || newInterval[1] < intervals[p][0]){
            ans.add(new int[]{start, newInterval[1]});
        }
        else{
            ans.add(new int[]{start, intervals[p][1]});
            p++;
        }
        // left
        while(p < intervals.length){
            ans.add(intervals[p++]);
        }
        // transform
        int[][] ans_ = new int[ans.size()][2];
        for (int i = 0; i < ans_.length; i++) ans_[i] = ans.get(i);
        
        return ans_;
    }
}
```
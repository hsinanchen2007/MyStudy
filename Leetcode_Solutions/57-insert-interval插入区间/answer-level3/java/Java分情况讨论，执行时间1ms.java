分情况讨论，确定涉及到的新合并区间的start和end
![微信图片_20200220103551.png](https://pic.leetcode-cn.com/c01e8b3cad10571c898edd1b48a708e69d571e534c61d50b331e0bcc89f1855b-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200220103551.png)
/*
一、确定start：
1.寻找第一个“终点大于或等于newInterval起点”的intervals[i]对应的i（下标），找到就退出循环。该过程中把未涉及到的前面的区间都加入结果数组。
2.若找不到，说明新区间排在最后且无重叠，直接返回；
3.若找到，取等于，说明newInterval起点与intervals[i]终点重合，start为intervals[i]的起点；
4.若找到，取大于，分情况讨论intervals[i]和newInterval的起点的关系，确定新的start(取小的)
二、确定end：
1.寻找第一个“终点大于或等于newInterval终点”的intervals[i]对应的i（下标），找到就退出循环。
2.若找不到，说明新区间的终点最大，设置end后直接返回；
3.若找到，取等于，设置end为新区间终点，将合并后的区间加入结果数组。
4.若找到，取大于，分情况讨论intervals[i]的起点和newInterval的终点的关系：
  1°若intervals[i]的起点<=newInterval的终点，说明两区间重叠，end=intervals[i][1]，将合并后的区间加入结果数组；
  2°否则说明两区间不重叠，end=newInterval[1]，分别把两区间加入结果数组。
三、将i之后的区间加入结果数组，return；
*/
```
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        if(intervals.length == 0)
            return new int[][]{newInterval};
        if(newInterval.length == 0)
            return intervals;
        List<int[]> list_res = new ArrayList<>();
        int start, end;
        int i = 0;
        for(i = 0; i < intervals.length && intervals[i][1] < newInterval[0]; i++){
            list_res.add(intervals[i]);
        }
        //新区间应排在最后
        if(i == intervals.length){
            list_res.add(newInterval);
            return list_res.toArray(new int[list_res.size()][]);
        }
        //新区间刚好接在已存在区间之后
        if(intervals[i][1] == newInterval[0])
            start = intervals[i][0];
        else{
            //比较新区间的start和后面一个区间的start，确定新的start
            if(intervals[i][0] <= newInterval[0])
                start = intervals[i][0];
            else start = newInterval[0];
        }
        while(i < intervals.length && intervals[i][1] < newInterval[1])
            i++;
        //新区间的ending最大
        if(i == intervals.length){
            end = newInterval[1];
            list_res.add(new int[]{start, end});
            return list_res.toArray(new int[list_res.size()][]);
        }
        //新区间和已存在区间ending相同
        if(intervals[i][1] == newInterval[1]){
            end = intervals[i][1];
            list_res.add(new int[]{start, end});
        }
        else{
            //旧区间的start小于等于新区间的ending
            if(intervals[i][0] <= newInterval[1]){
                end = intervals[i][1];
                list_res.add(new int[]{start, end});
            }
            else{
                end = newInterval[1];
                list_res.add(new int[]{start, end});
                list_res.add(intervals[i]);
            } 
        }
        for(i++; i < intervals.length; i++){
            list_res.add(intervals[i]);
        }
        return list_res.toArray(new int[list_res.size()][]);
    }
}
```

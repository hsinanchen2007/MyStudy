### 解题思路
先对区间排序，维护两个变量from,to,分别代表区间的上下jie，然后遍历数组，比较相邻的两个区间大小，来更新from，to。
两个区间的关系就三种可能：全包含，半包含，不包含。全包含from,to不动;半包含更新to;不包含时保存from和to,同时置from，to为当前元素值。
最后不要忘记最后一次循环时要保存当前from，to。

### 代码

```java
class Solution {
    public int[][] merge(int[][] intervals) {
    if(intervals == null || intervals.length == 0 || intervals.length == 1){
      return intervals;
    }
    
    Arrays.sort(intervals, Comparator.comparingInt(o -> o[0]));
    
    List<int[]> res = new ArrayList<>();
    int from = intervals[0][0];
    int to = intervals[0][1];

    for(int i = 1; i<intervals.length;i++){
      if(intervals[i][1] <= to){
        // ignore
      }else if(intervals[i][1] > to){
        if(intervals[i][0] <= to){
          to = intervals[i][1];
        }else{
          //save from to
          int[] s = new int[]{from,to};
          res.add(s);
          //reset
          from = intervals[i][0];
          to = intervals[i][1];
        }
      }
      if(i == intervals.length-1){
        //save from and to
        int[] s = new int[]{from,to};
        res.add(s);
      }
    }
    //transform
    int[][] s = new int[res.size()][2];
    for(int j= 0;j<res.size();j++){
      s[j]=res.get(j);
    }
    return s;
    }
}
```
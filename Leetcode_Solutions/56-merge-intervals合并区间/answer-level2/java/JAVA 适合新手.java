刚看到题就想起了435题求最大无重叠空间的贪心解法，其实这道题感觉也可以可以套用。

首先按照区间的起始位置从小到大排序，保证遍历的时候，每个区间起始位置都是最小的。
然后遍历所有区间，设置end数组表示上一个区间的起始位置和结束位置
end[1] >= val[0],说明val这个区间与end区间重叠，如果 end[1] < val[1]，则更新end[1]，保证end是两个区间合并之后的区间。
end[1] >= val[0]，两区间不重叠，将前一个重叠区间结果end加入到结果集，再更新end           

```
public int[][] merge(int[][] intervals) {
       if(intervals == null || intervals.length == 0) return new int[0][0];
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });
        int[] end = intervals[0];
        List<int[]> result = new ArrayList();
        for(int[] val : intervals){
            if(end[1] >= val[0]){
                //加入区间
                if(end[1] < val[1]){
                    end[1] = val[1];
                }
            }else{
                //非重叠，加入结果
                result.add(new int[]{end[0], end[1]});
                //更新
                end = val;
            }
        }
        result.add(new int[]{end[0], end[1]});
        return result.toArray(new int[result.size()][]);
    }
```

最后推荐刷一波不重叠区间类似的题目，例如435，451。
仓促之下写的，希望对你有所帮助。
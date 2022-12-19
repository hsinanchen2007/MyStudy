按几种情况分类讨论：
    1.移除区间和当前区间相离（移除的最大值和最小值都不在区间内，没有交点，但是这里不包含移除区间覆盖当前区间的情况）
    2.移除区间和当前区间相切（这里相切是指有一个值在区间内，另一个不在的情况，不是数学意义上的相切，但是有相似的地方，就是只有一个“交点”。我自己发明的一个说法，数学大佬不要来喷我。我就只是想表达一个思路而已）
    3.移除区间和当前区间相交（移除区间完全在当前区间内，有两个焦点）
    4.移除区间覆盖了当前区间，这个区间全部移除的情况（这个好像可以叫内含吧……）

另外有看到别的题解写了用二分插入的方式解决，这里我是没有想明白，有大佬明白的话，请留个言，我也来学习学习
```
    public List<List<Integer>> removeInterval(int[][] intervals, int[] toBeRemoved) {
        int removeMin = toBeRemoved[0];
        int removeMax = toBeRemoved[1];
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0;i<intervals.length;i++){
            // 如果移除区间最大值比当前区间最小值还小或者移除区间最小值比比当前区间最大值要大
            if (removeMax < intervals[i][0] || removeMin >= intervals[i][1]){
                result.add(getEveryList(intervals[i][0],intervals[i][1]));// 当前区间不移除
            }else if(removeMin > intervals[i][0] && removeMax >= intervals[i][1]){
                // 移除区间的头部在当前区间内，但是尾部在当前区间外
                result.add(getEveryList(intervals[i][0],removeMin));
            }else if (removeMin <= intervals[i][0] && removeMax < intervals[i][1]){
                // 移除区间尾部在当前区间内，但是头部在当前区间外
                result.add(getEveryList(removeMax,intervals[i][1]));
            }else if(removeMin > intervals[i][0] && removeMax < intervals[i][1]){
                // 移除区间在当前区间内的
                result.add(getEveryList(intervals[i][0],removeMin));
                result.add(getEveryList(removeMax,intervals[i][1]));
            }else {
                continue;
            }
        }
        return result;
    }

    private List<Integer> getEveryList(int min,int max){
        List<Integer> everyOne = new ArrayList<>();
        everyOne.add(min);
        everyOne.add(max);
        return everyOne;
    }
```

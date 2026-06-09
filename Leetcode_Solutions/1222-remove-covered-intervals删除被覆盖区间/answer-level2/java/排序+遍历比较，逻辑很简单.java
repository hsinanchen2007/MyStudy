先对原始数组进行排序，左边界升序，右边界降序，这样遍历比较时只需要考虑右边界即可。以此保证左边界相同时，右边的都是可以删除的。用一个符号max记录当前最大的有边界，当左边界不同时，当前右边界的若小于前一个，则可删除，否则就比较当前右边界和上一个哪一个较大，替换max。
```
class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals,new Comparator<>(){
            public int compare(int[] o1,int[] o2){
                if(o1[0]==o2[0]){
                    return o2[1]-o1[1];
                }else{
                    return o1[0]-o2[0];
                }
            }
        });
        int count=intervals.length,res=count;;
        int max=intervals[0][1];
        for(int i=1;i<count;i++){
            if(intervals[i][1]<=max){
                res--;
            }else{
                max=Math.max(max,intervals[i][1]);
            }
        }
        return res;
    }
}
```

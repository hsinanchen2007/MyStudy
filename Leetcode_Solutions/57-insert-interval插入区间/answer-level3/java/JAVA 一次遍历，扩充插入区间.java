遍历intervals数组，同时与待插入区间比较，同时寻找机会插入
如果已经把待插入区间插入，接下来就是直接插入剩余区间continue
如果只是单纯扩充了待插入区间，还要遍历下一个区间，直到结束
如果全部遍历结束新区间还未添加到结果中，则添加。

1ms 99.7%
```
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        
        List<int[]> ans = new ArrayList();
        if(intervals.length==0) {
            ans.add(newInterval);
            return ans.toArray(new int[ans.size()][]);
        }

        boolean flag = false;
        for(int[] intv : intervals){
            if(flag){
                ans.add(intv);
                continue;
            }

            //如果新区间已经被原有区间覆盖，直接返回原有区间
            if(intv[0]<=newInterval[0] && intv[1] >= newInterval[1]){
                return intervals;
            }
            
            if(intv[0] >= newInterval[0] 
                && intv[0] <= newInterval[1]){
                newInterval[1] = Math.max(newInterval[1],intv[1]);    
            }else if(intv[0] <= newInterval[0] 
                        && intv[1] >= newInterval[0]){
                newInterval[0] = intv[0];
                newInterval[1] = Math.max(newInterval[1],intv[1]);
            }else if(intv[0] > newInterval[1]){
                flag = true;
                ans.add(newInterval);
                ans.add(intv); 
            }else if(intv[1] < newInterval[0]){
                ans.add(intv);
            }
        }
        //如果之前还没有插入
        if(!flag) ans.add(newInterval);

        return ans.toArray(new int[ans.size()][]);


    }
}
```

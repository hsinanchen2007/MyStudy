### 解题思路
借鉴id为 我不是混子 的解法，java完成

### 代码

```java
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        //如果区间为空，则直接返回新区间
        if(intervals.length==0 || intervals==null){
            return new int[][]{{newInterval[0],newInterval[1]}};
        }
        List<int[]> list=new ArrayList<>();
        for(int i=0;i<intervals.length;i++){
            //如果当前区间的最大值比新区间小，将当前加入结果中，进入下一个区间
            if(intervals[i][1]<newInterval[0]){
                list.add(intervals[i]);
                if(i==intervals.length-1) list.add(newInterval);
                continue;
            }
            //如果当前区间的最小值都大于新区间，则将新区间和剩余区间都加入结果中
            if(intervals[i][0]>newInterval[1]){
                list.add(newInterval);
                //后面的直接加入结果
                for(;i<intervals.length;i++){
                    list.add(intervals[i]);
                }
                break;
            }
            //否则将当前区间和新区间合并为新区间
            newInterval[0]=Math.min(newInterval[0],intervals[i][0]);
            newInterval[1]=Math.max(newInterval[1],intervals[i][1]);
            if(i==intervals.length-1){
                list.add(newInterval);
            }
        }
       return list.toArray(new int[list.size()][]);
    }
}
```
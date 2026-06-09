### 解题思路
java 排序后筛选

### 代码

```java
class Solution {
    public int[][] merge(int[][] intervals) {
        if(intervals==null|| intervals.length<=1)
        return intervals;
        List<int[]> list=new ArrayList<>();
        Arrays.sort(intervals,new Comparator<int[]>(){
            @Override
            public int compare(int[] a,int[] b){
                return a[0]-b[0];
            }
        });
        for(int i=0;i<intervals.length;++i)
        {
            int begin=intervals[i][0],end=intervals[i][1];
            while(i<intervals.length-1&&end>=intervals[i+1][0])
            {
                end=end>intervals[i+1][1]?end:intervals[i+1][1];
                i++;
            }
            list.add(new int[]{begin,end});
        }
        return list.toArray(new int[list.size()][2]);
    }
}
```
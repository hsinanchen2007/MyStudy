### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] merge(int[][] intervals) {
        int len=intervals.length;
        if(len==0||len==1){
            return intervals;
        }
        
        List<int[]> list=new ArrayList<>();//用来保存输出区间数组
        Arrays.sort(intervals,new Comparator<int[]>(){//区间问题先排序
            public int compare(int[] a,int[] b){
                return a[0]-b[0];
            }
        });
        
        int start=intervals[0][0];
        int end=intervals[0][1];
        
        for(int[] inter:intervals){
            if(inter[0]<=end){//若end大于等于左区间则合并
                end=Math.max(end,inter[1]);
            }else{//否则则记录，并开始下一轮
                list.add(new int[]{start,end});
                start=inter[0];
                end=inter[1];
            }
        }
        
        list.add(new int[]{start,end});//防止最后从合并区间的情况下出来
        
        return list.toArray(new int[list.size()][2]);
    }
}
```
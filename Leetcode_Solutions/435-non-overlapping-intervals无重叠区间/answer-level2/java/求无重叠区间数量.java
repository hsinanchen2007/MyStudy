### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        if(intervals.length==0){
            return 0;
        }
        Arrays.sort(intervals,new Comparator<int[]>(){//按end升序排序
            public int compare(int[] a,int[] b){
                return a[1]-b[1];
            }
        });
        
        int count=1;
        int xEnd=intervals[0][1];//排序后第一个区间是interval[0]
        for(int[] interval:intervals){//
            if(interval[0]>=xEnd){//找到下一个选择区间继续
                count++;
                xEnd=interval[1];
            }
        }
        return intervals.length-count;
    }
}
```
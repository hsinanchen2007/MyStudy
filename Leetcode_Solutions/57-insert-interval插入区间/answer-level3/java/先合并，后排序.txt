### 解题思路
要么先将newInterval插入intervals中，然后根据start点排序;
要么就先合并newInterval到intervals中，然后再一起排序。
此代码选择了后者：
### 代码

```java
class Solution {
    private class SortComparator implements Comparator<int[]>
    {
        public int compare(int[] a,int[] b)
        {
            return Integer.compare(a[0], b[0]);
        }
    }
    private boolean couldInsert(int[] newInterval,int[] interval)
    {
        if(newInterval[0]>=interval[0]&&newInterval[0]<=interval[1])
            return true;
        if(interval[0]>=newInterval[0]&&interval[0]<=newInterval[1])
            return true;
        return false;
    }
    private int[][] nComplexityInsert(int[][] intervals,int[] newInterval)
    {
        int rowlen=intervals.length;
        for(int i=0;i<intervals.length;i++)
        {
            int maxend=Math.max(intervals[i][1], newInterval[1]);
            int minstart=Math.min(intervals[i][0], newInterval[0]);
            if(couldInsert(newInterval,intervals[i]))
            {
                newInterval[0]=minstart;
                newInterval[1]=maxend;
                intervals[i][0]=intervals[i][1]=-1;
                rowlen--;
            }
        }
        if(rowlen==0)return new int[][]{newInterval};
        int[][] ans=new int[rowlen+1][2];
        ans[0]=newInterval;
        for(int i=0,j=1;i<intervals.length;i++)
        {
            if(intervals[i][0]!=-1&&intervals[i][1]!=-1)
            {
                ans[j++]=intervals[i];       
            }
        }
        Arrays.sort(ans,new SortComparator());
        return ans;
    }
    public int[][] insert(int[][] intervals, int[] newInterval) {
        if(intervals.length==0)
            return new int[][]{newInterval};
        return nComplexityInsert(intervals,newInterval);
    }
}
```
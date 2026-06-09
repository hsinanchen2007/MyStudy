### 解题思路
思路很简单，就是先对二维数组intervals[][]进行排序，按照每一个的起点intervals[i][0]从小到大进行排序，然后开始遍历：
如果intervals[i+1][0]<=intervals[i][1]，即说明可以合并，合并步骤：
intervals[i+1][0]=intervals[i][0];
intervals[i+1][1]=max(intervals[i][1],intervals[i+1][1]);
同时令intervals[i]为(-1,-1)，方便后面的返回答案。
### 最主要的是怎么进行排序？
Java中Arrays的静态类sort()方法可以对一维数组进行排序，但是如何对二维数组排序？
我是这么想的：如果将二维数组m[][]传入时，Java比较的元素将是m[],而m[]显然是无法比较的，那么就需要继承比较接口Comparator<int[]>，重写compare方法为:
将m[i]当成a,那么起点自然为a[0]
```
public int compare(int[] a,int[] b)
{
    return Integer.compare(a[0], b[0]);
}
```

只需要传入继承比较接口Comparator<int[]>的类就可以了。
### 代码

```java
class Solution {

    public int[][] merge(int[][] intervals) {
        if(intervals.length==0)
            return new int[0][0];
        return sortMerge(intervals);
    
    }
    private class myComparator implements Comparator<int[]>
    {
        public int compare(int[] a,int[] b)
        {
            return Integer.compare(a[0], b[0]);
        }
    }
    private void sortMatrix(int intervals[][])
    {
        Arrays.sort(intervals,new myComparator());
    }
    /**o(nlogn) complexity**/
    private int[][] sortMerge(int[][] intervals)
    {
        sortMatrix(intervals);
        int rowlen=intervals.length;
        for(int i=0;i<intervals.length-1;i++)
        {
            int maxend=Math.max(intervals[i][1],intervals[i+1][1]);
            if(intervals[i+1][0]<=intervals[i][1])
            {
                intervals[i+1][0]=intervals[i][0];
                intervals[i+1][1]=maxend;
                intervals[i][0]=intervals[i][1]=-1;
                rowlen--;
            }
        }
        int ans[][]=new int[rowlen][2];
        for(int i=0,j=0;i<intervals.length;i++)
        {
            if(intervals[i][0]!=-1&&intervals[i][1]!=-1)
            {
                ans[j][0]=intervals[i][0];
                ans[j][1]=intervals[i][1];
                j++;
            }
        }
        return ans;
    }
}
```
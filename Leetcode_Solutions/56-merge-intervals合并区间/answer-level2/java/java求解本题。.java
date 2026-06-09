### 解题思路
1：将二维数组转化为两个1维数组，分别表示新区间的最小值和最大值
2：两个数组分别排序
3：从小到大遍历最小值的数组，如果某一位大于前面的最大值，说明前面的构成一个区间了，就把区间值填到结果数组中。如果不大于，就求解当前的区间最大值。

### 代码

```java

import java.util.Arrays;
class Solution {
    public int[][] merge(int[][] intervals) {
          int[][] res=new int[intervals.length][2];
         if(intervals==null||intervals.length==0||intervals[0].length==0)
            return res;
         int[] a=new int[intervals.length];
         int[] b=new int[intervals.length];
         for(int i=0;i<intervals.length;i++){
             a[i]=intervals[i][0];
             b[i]=intervals[i][1];
         }
         Arrays.sort(a);
         Arrays.sort(b);
          int count=0;
          int start=a[0];
          int end=b[0];
         for(int i=1;i<a.length;i++){
             if(a[i]>end){
                 res[count][0]=start;
                 res[count][1]=end;
                 start=a[i];
                 end=b[i];
                 count++;
             }
             else{
                 end=Math.max(end,b[i]);
             }
         }
          res[count][0]=start;
          res[count][1]=end;
          if(count==intervals.length) return res;
          else{
              int[][] newres=new int[count+1][2];
              for(int i=0;i<=count;i++){
              newres[i][0]=res[i][0];
              newres[i][1]=res[i][1];
               }
               return newres;
          }
    }
}
```
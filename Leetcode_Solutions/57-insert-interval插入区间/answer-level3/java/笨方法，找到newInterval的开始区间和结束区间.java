执行结果：
通过
显示详情
执行用时 :
3 ms
, 在所有 Java 提交中击败了
87.55%
的用户
内存消耗 :
41.7 MB
, 在所有 Java 提交中击败了
65.72%
的用户
```
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int x = intervals.length;
        if(x==0){
           if(newInterval.length!=0){
               return new int[][]{newInterval};
           } else{
               return null;
           }
        }
       
        int pos = -1;
        if(newInterval[1]<intervals[0][0]){
             int[][] res = new int[x+1][2];
            res[0][0]=newInterval[0];
             res[0][1]=newInterval[1];
            System.arraycopy(intervals,0,res,1,x);
            return res;
        }
        if(newInterval[0]>intervals[x-1][1]){
             int[][] res = new int[x+1][2];
            System.arraycopy(intervals,0,res,0,x);
             res[x][0]=newInterval[0];
             res[x][1]=newInterval[1];
            return res;
        }
        int start=0;
        for(int i=0; i<x; i++){
            if(newInterval[0]<intervals[i][0]&&newInterval[1]<intervals[i][0]){
                 int[][] res = new int[x+1][2];
                System.arraycopy(intervals,0,res,0,i);
                 res[i][0]=newInterval[0];
                 res[i][1]=newInterval[1];
                 System.arraycopy(intervals,i,res,i+1,x-i);
                return res;
            }
            if(newInterval[0]<=intervals[i][0]){
                intervals[i][0]=newInterval[0];
                start=i;
                break;
            }else  if(newInterval[0]<=intervals[i][1]){
                start=i;
                break;
            }
        }
        int end=-1;
        for(int i=start; i<x; i++){
            if(newInterval[1]<intervals[i][0]){
                intervals[i-1][1]=newInterval[1];
                end=i-1;
                break;
            } else if(newInterval[1]==intervals[i][0]||newInterval[1]<=intervals[i][1]){
                end=i;
                break;
            }
        }
        if(end==-1){
            end=x-1;
            intervals[x-1][1]=newInterval[1];
        }
        if(end==start)return intervals;
         int[][] res = new int[x-(end-start)][2];
        intervals[start][1]=intervals[end][1];
        System.arraycopy(intervals,0,res,0,start+1);
         System.arraycopy(intervals,end+1,res,start+1,x-end-1);
        return res;
    }
}
```

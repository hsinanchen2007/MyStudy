### 解题思路
看注释可以明白
### 代码

```java
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        if(intervals.length==0)return new int[][]{{newInterval[0],newInterval[1]}};
        List<int[]> res=new ArrayList();
        boolean b=false;//表示newInterval是否插入了区间
        int row;
        for(row=0;row<intervals.length;row++){
            if(newInterval[0]>intervals[row][1]){
                res.add(intervals[row]);
                continue;
            }
            b=true;
            if(newInterval[1]<intervals[row][0]){//说明newInterval没有相交区间。
                res.add(newInterval);
                res.add(intervals[row]);
                row++;
                break;
            }
            //相交了
            int left=Math.min(newInterval[0],intervals[row][0]);
            while(row+1<intervals.length&&newInterval[1]>=intervals[row+1][0]){
                row++;//遍历后面的区间直到不与newInterval相交
            }
            int right=Math.max(newInterval[1],intervals[row][1]);
            res.add(new int[]{left,right});
            row++;
            break;
        }
        if(!b)res.add(newInterval);//说明newInterval比如何区间都大，夹在末尾
        for(;row<intervals.length;row++){//intervals剩余的区间原样加入
            res.add(intervals[row]);
        }
        return res.toArray(new int[res.size()][]);
        
    }
}
```
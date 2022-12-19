### 解题思路
![111111.png](https://pic.leetcode-cn.com/6ff1157acb17eeb8edcd223b0b794fd4c2959820023d41da727182000a37a86e-111111.png)

整体思路是把intervals数组分成左中右三部分,左边是new之前的，中间是重合的，右边是new之后的。
中间部分，判断new的左右边界和原数组重合处最左和最右的关系，包含还是要叠加，最后融合成一个[]，再把三个合并。



### 代码

```java
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        if (intervals==null || intervals.length==0){//如果intervals为空，则返回newInterval
            List<int[]> l1=new ArrayList<>();
            l1.add(newInterval);
            return l1.toArray(new int[0][]);
        }
//        if (intervals.length==1){
//            if (newInterval[1]<intervals[0][0]){
//                List<int[]> l1=new ArrayList<>();
//                l1.add(newInterval);
//                l1.add(intervals[0]);
//                return l1.toArray(new int[0][]);
//            }
//            else if (newInterval[0]<intervals[0][0] && newInterval[1]>=intervals[0][0] && newInterval[1]<=intervals[0][1]){
//                intervals[0][0]=newInterval[0];
//                return intervals;
//            }
//            else if (newInterval[0]>=intervals[0][0] && newInterval[0]<=intervals[0][1] && newInterval[1]>=intervals[0][0] && newInterval[1]<=intervals[0][1])
//                return intervals;
//            else if (newInterval[0]>=intervals[0][0] && newInterval[0]<=intervals[0][1] && newInterval[1]>intervals[0][1]) {
//                intervals[0][1] = newInterval[1];
//                return intervals;
//            }
//            else if (newInterval[0]>intervals[0][1]){
//                List<int[]> l1=new ArrayList<>();
//                l1.add(intervals[0]);
//                l1.add(newInterval);
//                return l1.toArray(new int[0][]);
//            }
//            else if (newInterval[0]<intervals[0][0] && newInterval[1]>intervals[0][1]){
//                List<int[]> l1=new ArrayList<>();
//                l1.add(newInterval);
//                return l1.toArray(new int[0][]);
//            }
//        }
        int start=-1,end=-1;//分别是重合部分的开始和结束
        boolean s=false,e=false;//s表示new的左端是否与原区间相交，true为不相交，e表示new的右端是否与原区间相交，true为不相交
        List<int[]> l1=new ArrayList<>();
        for (int i=0;i<intervals.length;i++){//检测new的左端位于区间的哪个位置（与区间的右端点比较）
            if (newInterval[0]<=intervals[i][1]){
                start=i;
                s= newInterval[0] >= intervals[i][0];
                break;
            }
            else
                l1.add(intervals[i]);
        }
        List<int[]> l2=new ArrayList<>();
        for (int i=intervals.length-1;i>=0;i--){//检测new的右端位于区间的哪个位置（与区间的左端点比较）
            if (newInterval[1]>=intervals[i][0]){
                end=i;
                e=newInterval[1] <= intervals[i][1];
                break;
            }
            else
                l2.add(0,intervals[i]);
        }

        int a=0,b=0;
        if (start==-1 || end==-1){//说明new与原区间不相交，直接并就可以
            l1.add(new int[] {newInterval[0],newInterval[1]});
            l1.addAll(l2);
            return l1.toArray(new int[0][]);
        }
        if (s)//new左侧与原左区间相交
            a=Math.min(newInterval[0],intervals[start][0]);
        else//new左侧与原左区间不相交
            a=newInterval[0];
        if (e)//new右侧与原右区间相交
            b=Math.max(newInterval[1],intervals[end][1]);
        else//new右侧与原右区间不相交
            b=newInterval[1];
        l1.add(new int[] {a,b});
        l1.addAll(l2);
        return l1.toArray(new int[0][]);
    }
}
```
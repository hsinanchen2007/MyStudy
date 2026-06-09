### 解题思路
此处撰写解题思路
把大的区间list分为在新区间左边跟新区间右边
左边：意味着intervals[i][1]<newInterval[0],直接插入temp
右边：意味着intervals[i][0]>newInterval[1],直接插入temp
中间，那么就是newinterval[0]>intervals[i][1] && newinterval[1]<intervals[i][0](两个i不一样，是一直递增的index)
因为从左边跳出来，那就满足左边的条件，那么只需要每次都判断右边的条件是否不符合即可，即
因为不符合，那么从左边出来的，又不符合右边，那就一直是在中间，可以进行最大值最小值的更新，存储在dur_temp里面，每次去最小最大值，初始值设置为newInterval即可
i<intervals.length && newInterval[1]>=intervals[i][0]
                        !(intervals[i][0]>newInterval[1]）
### 代码

```java
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {


        List<int[]> temp=new ArrayList<>();

        int i=0;
        while(i<intervals.length && newInterval[0]>intervals[i][1])
        {
            temp.add(intervals[i]);
            i++;
        }
        int[] dur_temp=new int[]{newInterval[0],newInterval[1]};
        while (i<intervals.length && newInterval[1]>=intervals[i][0])
        {
            dur_temp[0]=Math.min(dur_temp[0],intervals[i][0]);
            dur_temp[1]=Math.max(dur_temp[1],intervals[i][1]);
            i++;
        }
        temp.add(dur_temp);
        while(i<intervals.length)
        {
            temp.add(intervals[i]);
            i++;
        }
        return temp.toArray(new int[0][]);
    }
}
```
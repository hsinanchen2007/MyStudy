### 解题思路
此处撰写解题思路

### 代码

```java []
// 方案1 - 排序记录上一次结果，看着比较愚蠢
class Solution {
    public boolean canAttendMeetings(int[][] intervals) {
        Arrays.sort(intervals,(int[] item1,int[] item2) -> item1[0] - item2[0]);
        int[] last = null;
        for(int[] item : intervals) {
            if(last != null) {
                if(item[0] < last[1])
                {
                    return false;
                }
            }
            last = item;
        }
        //System.out.printf("%s",Arrays.deepToString(intervals));
        return true;
    }
}
```
```java []
// 方案二 官方实现，增加括号
class Solution {
    public boolean canAttendMeetings(Interval[] intervals) {
        Arrays.sort(intervals, new Comparator<Interval>() {
            public int compare(Interval i1, Interval i2) {
                return i1.start - i2.start;
            }        
        });
        //不用last方案，直接for循环少取一个进行比较，代码更加简洁
        for (int i = 0; i < intervals.length - 1; i++) {
            if (intervals[i].end > intervals[i + 1].start) {
                return false;
            } 
        }
        return true;
    }
}
```
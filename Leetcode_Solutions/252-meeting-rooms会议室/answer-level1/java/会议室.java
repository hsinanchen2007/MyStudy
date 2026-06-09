### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean canAttendMeetings(int[][] intervals) {
        if(intervals.length==0||intervals.length==1)
            return true;
        Arrays.sort(intervals,(o1,o2)->o1[0]==o2[0]? o1[1]-o2[1]:o1[0]-o2[0]);
        int r=intervals[0][1];
        for(int i=1;i<intervals.length;i++){
            if(intervals[i][0]<r)
                return false;
            r=intervals[i][1];
        }
        return true;
    }
}
```
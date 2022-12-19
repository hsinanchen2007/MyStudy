```
public class Solution implements Comparator<int[]>{
    public boolean canAttendMeetings(int[][] intervals){
        Arrays.sort(intervals,this);//通过指定比较器产生的顺序对指定对象数组intervals进行排序。
        for(int i=0;i<intervals.length-1;i++){
            if(intervals[i][1]>intervals[i+1][0]){//检查前一个数组end是否不大于后面数组的start
                return false;
            }
        }
        return true;
    }
    public int compare(int[] t1,int[] t2){//数组中的所有元素t1和t2通过compare(t1,t2)方法产生顺序，即按照会议start时间排序。
        return t1[0]-t2[0];
    }
}
```

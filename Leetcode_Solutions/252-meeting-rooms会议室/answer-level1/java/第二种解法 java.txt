class Solution {
    public boolean canAttendMeetings(int[][] intervals) {
        if(intervals.length<2)return true;
        Arrays.sort(intervals,Comparator.comparingInt(o -> o[0]));
        //只用排序，不用intervals类
        int last = intervals[0][1];
        for(int i = 1 ; i<intervals.length;i++){
            if(last>intervals[i][0])return false;
            last = intervals[i][1];
        }
        return true;
    }
}
    
    class Solution {
        public int[][] insert(int[][] intervals, int[] newInterval) {
            List<int[]> list = new ArrayList<>();
            // 1. add newInterval pre
            int i = 0;
            for( ;i < intervals.length && intervals[i][0] <= newInterval[0];i++) {
                list.add(intervals[i]);
            }
            // 2. add newInterval
            if(i == 0) {
                list.add(newInterval);
            }else {
                int[] temp = list.get(list.size() - 1);
                if(newInterval[0] >= temp[0] && newInterval[0] <= temp[1]) {
                    temp[1] = temp[1] > newInterval[1] ? temp[1] : newInterval[1];
                }else {
                    list.add(newInterval);
                }
            }
            // 3. add newInterval next
            for( ;i < intervals.length;i++) {
                int[] temp = list.get(list.size() - 1);
                if(intervals[i][0] >= temp[0] && intervals[i][0] <= temp[1]) {
                    temp[1] = temp[1] > intervals[i][1] ? temp[1] : intervals[i][1];
                }else {
                    list.add(intervals[i]);
                }
            }
            return list.toArray(new int[list.size()][2]);
        }
    }
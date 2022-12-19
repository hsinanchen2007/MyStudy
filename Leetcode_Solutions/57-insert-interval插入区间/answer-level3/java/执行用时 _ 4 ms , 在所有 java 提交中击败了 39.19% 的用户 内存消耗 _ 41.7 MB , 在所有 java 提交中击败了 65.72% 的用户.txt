    class Solution {
        public int[][] insert(int[][] intervals, int[] newInterval) {
            int length = intervals.length;
            int[][] newIntervals = new int [length+1][];
            for (int i = 0; i < length;i++) {
                newIntervals[i] = intervals[i];
            }
            newIntervals[length] = newInterval;
            return merge(newIntervals);
        }

        public int [][] merge(int[][] intervals) {
            List<int[]> ans = new ArrayList();

            if (null == intervals || intervals.length == 0) {
                return ans.toArray(new int [0][]);
            }

            Arrays.sort(intervals,new Comparator<int[]>(){
                @Override
                public int compare(int[] o1,int[] o2) {
                    return o1[0] - o2[0];
                }
            });

            int i = 0;
            while ( i < intervals.length) {
                int left = intervals[i][0];
                int right = intervals[i][1];

                while (i < intervals.length - 1 && right >= intervals[i+1][0]) {
                    i++;
                    right = Math.max(right,intervals[i][1]);
                }
                ans.add(new int[] {left,right});
                i++;
            }
            return ans.toArray(new int[0][]);
        }
    }
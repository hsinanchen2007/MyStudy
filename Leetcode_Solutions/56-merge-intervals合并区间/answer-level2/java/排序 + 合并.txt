class Solution {
    private class IntverComparator implements Comparator<int[]>{

        @Override
        public int compare(int[] o1, int[] o2) {
            return o1[0]-o2[0];
        }
    }

    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals,new IntverComparator());
        List<int[]> ans = new ArrayList<>();
        int index = 0,n=intervals.length;
        while (index<n){
            int left = intervals[index][0];
            int right = intervals[index][1];
//            int next_left = intervals[index+1][0];
//            int next_right = intervals[index+1][1];
            while(index+1<n&&right>=intervals[index+1][0]){
                int next_right = intervals[index+1][1];
                right = Math.max(next_right,right);
                index++;
            }
            ans.add(new int[]{left,right});
            index++;
        }
        return ans.toArray(new int[0][]);
    }
}
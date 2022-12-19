执行用时 :7 ms, 在所有 java 提交中击败了92.22% 的用户
内存消耗 :44.1 MB, 在所有 java 提交中击败了61.03%的用户
```
class Solution {
   public class IntervalsComparator implements Comparator<int[]> {
		@Override
		public int compare(int[] o1, int[] o2) {
			return o1[0] - o2[0];
		}
	}
    public int[][] merge(int[][] intervals) {
        if(intervals == null || intervals.length < 1 || intervals[0].length < 1)
            return intervals;
        Arrays.sort(intervals, new IntervalsComparator());
        List<int[]> list = new ArrayList();
        int end = intervals[0][1];
        int start = intervals[0][0];
        for(int i = 0; i < intervals.length-1; i++){
            int startNext = intervals[i+1][0];
            int endNext = intervals[i+1][1];
            if(end < startNext){
                list.add(new int[]{start, end});
                start = startNext;
            }
            if(end < endNext){
                end = endNext;
            }
        }
        list.add(new int[]{start, end});
        return list.toArray(new int[list.size()][2]);
    }
}
```

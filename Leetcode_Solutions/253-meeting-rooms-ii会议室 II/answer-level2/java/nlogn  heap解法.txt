```
class Solution {
    public int minMeetingRooms(int[][] intervals) {
        PriorityQueue<Integer> heap=new PriorityQueue<>();
        Arrays.sort(intervals,(int[] a, int[] b)->a[0]-b[0]);
        int output=0;

        for (int i=0;i<intervals.length;i++){
            while (!heap.isEmpty() && intervals[i][0]>=heap.peek()){
                heap.poll();
            }
            heap.offer(intervals[i][1]);
            output=Math.max(output,heap.size());
        }

        return output;
    }
}
```

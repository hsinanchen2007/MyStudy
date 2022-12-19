```
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        if (trips.length == 0) return true;
        int seats = capacity; 
        // 按照出发位置排序
        Arrays.sort(trips, new Comparator<int[]> () {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[1] - o2[1];
            }
        });
        //根据到达位置排序的小根堆
        Queue<int[]> queue = new PriorityQueue<>(capacity, new Comparator<int[]> () {
            @Override 
            public int compare(int[] o1, int[] o2) {
                return o1[2] - o2[2];
            }
        });
        
        for (int[] t : trips) {
            if (seats == capacity) {
                seats -= t[0];
                queue.offer(t);
            } else {
               
                while (!queue.isEmpty() && t[1] >= queue.peek()[2]) {
                    seats += queue.peek()[0];
                    queue.poll();
                } 
                queue.offer(t);
                seats -= t[0];
                
            }
            if (seats < 0) return false;
        }
        return true;
    }
}
```

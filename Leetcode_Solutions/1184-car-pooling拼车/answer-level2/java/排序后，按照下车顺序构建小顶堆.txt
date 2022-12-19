### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        Arrays.sort(trips, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[1]==o2[1]?o1[2]-o2[2]:o1[1]-o2[1];
            }
        });
        
        Queue<int[]> queue = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[2]-o2[2];
            }
        });

        for(int i=0; i<trips.length; i++){
            while (!queue.isEmpty()&&queue.peek()[2]<=trips[i][1]){
                capacity+=queue.peek()[0];
                queue.poll();
            }
            if(capacity<trips[i][0]) return false;
            capacity-=trips[i][0];
            queue.add(trips[i]);
        }

        return true;
    }
}
```
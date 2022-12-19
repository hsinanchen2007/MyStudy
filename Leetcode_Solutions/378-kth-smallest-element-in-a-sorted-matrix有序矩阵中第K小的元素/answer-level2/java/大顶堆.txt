### 解题思路
此处撰写解题思路

### 代码

```java
import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<Integer> queue = new PriorityQueue<>(k, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (queue.size() < k) {
                    queue.offer(matrix[i][j]);
                }
                else if (matrix[i][j] < queue.peek()) {
                    queue.poll();
                    queue.offer(matrix[i][j]);
                }
            }
        }
        return queue.peek();
    }
}
```
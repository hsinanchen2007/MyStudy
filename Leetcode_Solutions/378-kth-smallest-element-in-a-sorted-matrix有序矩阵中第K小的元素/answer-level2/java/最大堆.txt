```
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<Integer> queue = new PriorityQueue<>(new Comparator<Integer>() {
            public int compare(Integer i1, Integer i2) {
                return i2 - i1;
            }
        });
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (queue.size() < k) {
                    queue.add(matrix[i][j]);
                    continue;
                }
                if (matrix[i][j] < queue.peek()) {
                    queue.poll();
                    queue.offer(matrix[i][j]);
                }
            }
        }
        return queue.peek();
    }
}
```

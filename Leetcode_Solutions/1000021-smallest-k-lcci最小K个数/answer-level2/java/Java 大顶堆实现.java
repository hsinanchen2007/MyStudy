利用Java的优先队列PriorityQueue简单实现大顶堆。
```java
class Solution {
    public int[] smallestK(int[] arr, int k) {
        if (arr == null || arr.length == 0 || k == 0) return new int[0];
        PriorityQueue<Integer> heap = new PriorityQueue<>(k + 1, (i1, i2) -> i2 - i1);
        for (int i : arr) {
            heap.offer(i);
            if (heap.size() > k) {
                heap.poll();
            }
        }
        int[] result = new int[k];
        for (int i = k - 1; i >= 0; i--) {
            result[i] = heap.poll();
        }
        return result;
    }
}
```

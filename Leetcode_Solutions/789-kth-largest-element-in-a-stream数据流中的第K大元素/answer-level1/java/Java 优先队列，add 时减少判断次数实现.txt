
```java
class KthLargest {
        private final PriorityQueue<Integer> queue;
        private int k;

        public KthLargest(int k, int[] nums) {
            queue = new PriorityQueue<>(k);
            this.k = k;
            for (int num : nums) {
                add(num);
            }
        }

        public int add(int val) {
            queue.offer(val);
            if (queue.size() > k) queue.poll();
            return queue.peek();
        }
}

```
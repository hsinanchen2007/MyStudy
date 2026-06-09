### 解题思路
维护一个大小为k的小顶堆。
如果小顶堆目前size小于k，则直接存放。
如果新增元素小于堆顶元素，则忽略；大于则删除堆顶元素，将新增元素加入优先队列。

### 代码

```java
class KthLargest {
    private final int k;
    private PriorityQueue<Integer> queue;

    public KthLargest(int k, int[] nums) {
        this.k = k;
        queue = new PriorityQueue<Integer>();
        for (int num : nums) {
            add(num);
        }
    }
    
    public int add(int val) {
        if (queue.size() < k) {
            queue.offer(val);
        } else if (queue.peek() < val) {
            queue.poll();
            queue.offer(val);
        }

        return queue.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
```
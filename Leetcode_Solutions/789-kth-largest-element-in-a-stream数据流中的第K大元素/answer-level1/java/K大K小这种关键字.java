### 解题思路
固有套路

### 代码

```java
class KthLargest {

    PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();
    int size = 0;

    public KthLargest(int k, int[] nums) {
        size = k;
        for (int i = 0; i < nums.length; i++) {
            if (priorityQueue.size() < k) {
                priorityQueue.add(nums[i]);
            } else {
                if (priorityQueue.peek() < nums[i]) {
                    priorityQueue.poll();
                    priorityQueue.add(nums[i]);
                }
            }
        }

    }

    public int add(int val) {
        if (priorityQueue.size() < size) {
            priorityQueue.add(val);
        } else {
            if (priorityQueue.peek() < val) {
                priorityQueue.poll();
                priorityQueue.add(val);
            }
        }
        return priorityQueue.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
```
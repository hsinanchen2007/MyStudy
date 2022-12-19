### 解题思路
此处撰写解题思路

### 代码

```java
class KthLargest {

    PriorityQueue<Integer> queue;
    int m = 0;

    public KthLargest(int k, int[] nums) {
        queue = new PriorityQueue<>();
        for(int i = 0; i < nums.length; i++){
            queue.add(nums[i]);
        }
        m = k;
    }

    public int add(int val) {
        queue.add(val);
        int size = queue.size() - m;
        for(int i = 0; i < size; i++){
            queue.poll();
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
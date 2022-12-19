### 解题思路
双端队列 更小的入队，比栈顶大的一直pop 每次返回队头 单调递减

### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums.length==0||k>nums.length) return new int[0];
        LinkedList<Integer> deque = new LinkedList<Integer>();
        int[] res = new int[nums.length-k+1];

        for (int i=0;i<k;i++) {
            while (!deque.isEmpty()&&nums[deque.getLast()]<nums[i]) {
                deque.removeLast();
            }
            deque.addLast(i);
        }
        res[0] = nums[deque.getFirst()];
        for (int i=k;i<nums.length;i++) {

            int pre = i-k;
            if (pre==deque.getFirst()){ //头部滑动
                deque.removeFirst();
            }
            while (!deque.isEmpty()&&nums[deque.getLast()]<nums[i]) { // 尾部滑动
                deque.removeLast();
            }
            deque.addLast(i);
            res[pre+1] = nums[deque.getFirst()];
        }
        return res;
    }

}
```
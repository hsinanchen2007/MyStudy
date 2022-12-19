### 解题思路
1. ArrayDeque的使用，双向队列。offerFirst，offerLast，pollFirst，pollLast，peekFirst，peekLast。
2. 使用双向队列，遍历nums数组。当队列为空时，将当前i值插入队列尾部。否则判断，当前插入i对应的元素是否大于队列尾部的元素，如果是，弹出队列尾部元素，直至队列为空或者队列尾部元素大于i对应元素。然后插入i值。
3. 再判断当前队列的头部元素是否在当前窗口中，如果不是，弹出头部元素（因为窗口最左侧的i值对应的nums数要么最大在队列头部，要么数小，在后序元素插入时被从尾部弹出）。
4. 如果i遍历到大于窗口长度时，开始添加结果集。

### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums == null || nums.length == 0 || k < 1) return new int[0];
        ArrayDeque<Integer> deque = new ArrayDeque<>();
        int[] res = new int[nums.length-k+1];
        for(int i = 0; i < nums.length; i++){
            while(!deque.isEmpty() && nums[deque.peekLast()] < nums[i]) deque.pollLast();
            if(!deque.isEmpty() && deque.peekFirst() == i - k) deque.pollFirst();
            deque.offerLast(i);
            if(i >= k-1) res[i-k+1] = nums[deque.peekFirst()];
        }
        return res;
    }
}
```
### 解题思路
使用双端队列保存一个单调递减的数组，则队列头永远是最大值
窗口移动时，往单调队列尾部加入数字，同时判断移除窗口值是不是最大值

### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        // k=0的情况
        if (k == 0) {
            return new int[] {};
        }
        // 求出第一个窗口的最大值,同时用双端队列保存单调递减数字
        Deque<Integer> queue = new LinkedList<>();
        for (int i = 0; i < k; i++) {
            while (!queue.isEmpty() && nums[i] > queue.getLast()) {
                queue.removeLast();
            }
            queue.addLast(nums[i]);
        }
        List<Integer> res = new ArrayList<>();
        res.add(queue.peek());
        // 遍历每个窗口
        for (int i = k; i < nums.length; i++) {
            // 如果移除窗口是值是最大值，则单调递减队列也要从头去掉一个数
            if (nums[i - k] == queue.peek()) {
                queue.poll();
            }
            // 单调递减队列进数,保证单调递减队列头永远是窗口内的最大值
            while (!queue.isEmpty() && nums[i] > queue.getLast()) {
                queue.removeLast();
            }
            queue.addLast(nums[i]);
            // 单调递减队列头永远是窗口内的最大值
            res.add(queue.getFirst());
        }
        return res.stream().mapToInt(Integer::intValue).toArray();
    }
}
```
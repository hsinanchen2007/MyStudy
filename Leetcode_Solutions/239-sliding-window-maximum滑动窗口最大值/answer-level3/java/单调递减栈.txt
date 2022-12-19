**思路**
区间范围内的最大值，可以使用单调栈解决，简单清晰明了。

1、维护一个单调递减栈stack，栈内元素为nums的下标值范围，按下标值对应的数组值维护stack的单调性
2、预处理先往栈stack 压进 k - 1 个元素
3、每次滑动，都是往栈stack 压进新增元素的下标值，维护栈。
4、判断栈的元素范围 i - stack.firstElement() 是否大于等于k，是的话表明栈内元素的范围过大了，即窗口长度范围大于k，把栈底元素去除即可，stack.removeElementAt(0)。
5、此时stack的栈底元素即为该次窗口的最大值。

**实现**
```
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return new int[0];
        }
        int length = nums.length;
        int[] array = new int[length - k + 1];
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < (k - 1); i++) {
            while (!stack.isEmpty() && nums[i] > nums[stack.peek()]) {
                stack.pop();
            }
            stack.push(i);
        }
        for (int i = k - 1; i < length; i++) {
            while (!stack.isEmpty() && nums[i] > nums[stack.peek()]) {
                stack.pop();
            }
            stack.push(i);
            if (i - stack.firstElement() >= k) {
                stack.removeElementAt(0);
            }
            array[i - k + 1] = nums[stack.firstElement()];
        }
        return array;
    }
}
```

# 思路
理解题目意思后就明白，是要寻找比当前数更大的下一个数，直接使用单调栈即可。

ps：关于单调栈，可以参考之前写过的题解
1、[https://leetcode-cn.com/problems/sliding-window-maximum/solution/dan-diao-di-jian-zhan-by-huangyt/]()
2、[https://leetcode-cn.com/problems/maximum-width-ramp/solution/dan-diao-di-jian-zhan-on-by-huangyt/]()

# 实现
```
class Solution {
    public int[] nextLargerNodes(ListNode head) {
        int[] arr = new int[10000];
        int[] valueArr = new int[10000];
        Stack<Integer> stack = new Stack<>();
        int length = 0;
        int value;
        while (head != null) {
            value = head.val;
            valueArr[length] = value;
            while (!stack.isEmpty() && value > valueArr[stack.peek()]) {
                arr[stack.pop()] = value;
            }
            stack.add(length);
            length++;
            head = head.next;
        }
        int[] result = new int[length];
        for (int i = 0; i < length; i++) {
            result[i] = arr[i];
        }
        return result;
    }
}
```
![image.png](https://pic.leetcode-cn.com/65387635444098645c86f826935edf618c1cfc9b5ab6f92ed091ea50f391a6b7-image.png)


### 解题思路
借助与一个实际的栈进行入栈操作。
1. 对于判断与pop顶部元素一致时，无需入栈。
2. 如果不一致，则需要判断当前栈顶元素是否是pop顶部的元素，一致则出栈且处理pop的下一个。
3. 如果不一致，则入栈。
4. push序列遍历完成，判断pop序列和剩余未出栈元素序列是否一致即可。

### 代码

```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        if (pushed == null && popped == null) {
            return true;
        }
        if (pushed == null || popped == null || pushed.length != popped.length) {
            return false;
        }

        Stack<Integer> stack = new Stack<Integer>();
        int i = 0, j = 0;
        while (i < pushed.length) {
            if (pushed[i] == popped[j]) {
                i++;
                j++;
                continue;
            } // 如果相等，则无需入栈，两个序列都向后继续遍历
            if (!stack.isEmpty() && stack.peek() == popped[j]) {
                j++;
                stack.pop();
                continue;
            } // 如果栈非空，则需要判断栈顶元素是否和当前pop元素一致，一致则出栈且pop序列向后走一个
            // 否则压栈，push序列向后走一个
            stack.push(pushed[i]);
            i++;
        }

        // 出上面循环说明push遍历结束，如果pop没有处理完，则序列判断剩余元素的出栈顺序是否和当前pop序列一致！！
        while (j < popped.length) {
            if (popped[j++] != stack.pop()) {
                return false;
            }
        }

        return true;

    }
}
```
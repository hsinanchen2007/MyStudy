### 解题思路
本题是经典的栈的例子，很多书都拿这个当例子。这里需要反转所以会用到队列，否则就是用另一个栈。
最后输出的时候可以继续使用队列，这里图省事用了StringBuffer。

### 代码

```java
class Solution {
    public String reverseParentheses(String s) {
        Stack<Character> stack = new Stack<>();
        Queue<Character> queue = new LinkedList();

        for (int i = 0; i < s.length(); i++) {
            Character ch = s.charAt(i);
            if (ch != ')') {
                stack.push(ch);
            } else {
                queue.clear();
                while (stack.peek() != '(') {
                    queue.add(stack.pop());
                }
                stack.pop();
                while (!queue.isEmpty()) {
                    stack.push(queue.poll());
                }
            }
        }

        StringBuffer buffer = new StringBuffer(stack.size());
        while (!stack.empty()) {
            buffer.append(stack.pop());
        }

        return buffer.reverse().toString();
    }
}
```
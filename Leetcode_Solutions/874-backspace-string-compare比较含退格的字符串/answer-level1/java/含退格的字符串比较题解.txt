### 解题思路
使用java的堆栈API:Stack。
碰到非#的字符，执行入栈操作；碰到#字符，执行出栈操作。
但是要特别注意，当栈为空时，不能执行出栈操作。
两个字符串都按照上述操作执行完后，先对比两个栈的大小是否相等，再对比两个栈的内容是否相等。

### 代码

```java
class Solution {
    public boolean backspaceCompare(String S, String T) {
        Stack<Character> stack1 = new Stack<>();
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) != '#') {
                stack1.push(S.charAt(i));
            } else {
                if (!stack1.isEmpty()) {
                    stack1.pop();
                }
            }
        }
        Stack<Character> stack2 = new Stack<>();
        for (int i = 0; i < T.length(); i++) {
            if (T.charAt(i) != '#') {
                stack2.push(T.charAt(i));
            } else {
                if (!stack2.isEmpty()) {
                    stack2.pop();
                }
            }
        }
        if (stack1.size() != stack2.size()) {
            return false;
        }
        for (int i = 0; i < stack1.size(); i++) {
            if (!stack1.pop().equals(stack2.pop())) {
                return false;
            }
        }
        return true;
    }
}
```
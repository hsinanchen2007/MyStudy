### 解题思路
栈的思想：每个元素入栈前，匹配栈顶元素，匹配则栈顶元素出栈，不匹配则将当前元素入栈，所有元素轮训一遍之后如果栈为空，则有效

### 代码

```java
class Solution {
    public boolean isValid(String s) {
        if (null == s || s.isEmpty()) {
            return true;
        }
        Stack<Character> stack = new Stack<>();
        stack.push(s.charAt(0));
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == ')' && !stack.isEmpty() && stack.peek() == '(') {
                stack.pop();
            } else if (s.charAt(i) == ']' && !stack.isEmpty() && stack.peek() == '[') {
                stack.pop();
            } else if (s.charAt(i) == '}' && !stack.isEmpty() && stack.peek() == '{') {
                stack.pop();
            } else {
                stack.push(s.charAt(i));
            }
        }
        if (stack.isEmpty()) {
            return true;
        }
        return false;
    }
}
```
### 解题思路

左括号入栈，右括号出栈。
遇到右括号：
    - 先判断当前栈是否为空，为空，说明右括号多，不匹配，提前返回 false；
    - 栈不为空，弹出栈顶：
        - 与当前右括号匹配的话，继续下一轮比较
        - 否则提前返回 false
最后判断栈是否为空

### 代码

```java
class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        if (s == null) return true;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i); // 获得当前字符
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else {
                if (stack.isEmpty()) return false;
                char left = stack.pop();
                if (left == '(' && c == ')') continue;
                if (left == '{' && c == '}') continue;
                if (left == '[' && c == ']') continue;
                else return false;
            }
        }
        return stack.isEmpty();
    }
}
```
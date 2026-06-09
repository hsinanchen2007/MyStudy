### 解题思路
括号匹配理解一点：连续性左括号的最后一个一定与后面第一个右括号匹配，否则为无效的括号序列。

### 代码

```java
class Solution {
    public boolean isValid(String s) {
        // 首先肯定需要匹配的字符为偶数个才可以进行配对
        if (s.length() % 2 != 0) return false;
        // 接下来运用堆栈进行数据的匹配
        Stack<Character> stack = new Stack();
        for (int i = 0;i < s.length();++i) {
            char current = s.charAt(i);
            if (current == '(' || current == '{' || current == '[') {
                stack.push(current);
            } else {
                if (stack.empty()) return false;
                char top = stack.peek();
                if (current == ')' && top != '(') {
                    return false;
                } else if (current == '}' && top != '{') {
                    return false;
                } else if (current == ']' && top != '[') {
                    return false;
                } else {
                    stack.pop();
                }
            }
        }
        return stack.empty();
    }
}
```
读到左括号时入栈
读到右括号时，若与栈顶的括号互为左右，则栈顶元素出栈；否则认为括号不匹配
最后栈全空时认为通过校验。

```
import java.util.*;
class Solution {
    public boolean isValid(String s) {
        if (s == null || s.isEmpty()) {
            return true;
        }

        Set<Character> leftSet = new HashSet<>(Arrays.asList('(', '[', '{'));

        Map<Character, Character> rightToLeft = new HashMap<>();
        rightToLeft.put(')', '(');
        rightToLeft.put(']', '[');
        rightToLeft.put('}', '{');

        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (leftSet.contains(ch)) {
                stack.push(ch);
            } else {
                if (stack.isEmpty()) {
                    return false;
                }
                if (!stack.peek().equals(rightToLeft.get(ch))) {
                    return false;
                }
                stack.pop();
            }
        }
        return stack.isEmpty();
    }
}
```

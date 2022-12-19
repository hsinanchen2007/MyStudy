左括号进栈，左括号出栈，最后判断出栈是否为对应括号或者为空即可

```
public boolean isValid(String s) {
        char[] str = s.toCharArray();
        if (str.length == 0) {
            return true;
        }
        Stack<Character> stack = new Stack<Character>();
        for (int i = 0; i < str.length; i++) {
            switch (str[i]) {
                case '(':
                    stack.push(')');
                    break;
                case '[':
                    stack.push(']');
                    break;
                case '{':
                    stack.push('}');
                    break;
                case ')':
                case ']':
                case '}':
                    if (stack.empty() || stack.pop() != str[i]) {
                        return false;
                    }
                    break;
            }
        }
        return stack.isEmpty();
    }
```

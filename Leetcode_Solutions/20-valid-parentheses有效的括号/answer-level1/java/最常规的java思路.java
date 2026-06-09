```java
class Solution {
    public boolean isValid(String s) {
        // 去空格
        s = s.replace(" ", "");
        // 栈存储数据
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if(stack.empty()) {
                stack.push(c);
            }
            else {
                if (c == ')') {
                    if (stack.peek() == '(') {
                        stack.pop();
                    }
                    else {
                        return false;
                    }
                }
                else if (c == '}') {
                    if (stack.peek() == '{') {
                        stack.pop();
                    }
                    else {
                        return false;
                    }
                }
                else if (c == ']') {
                    if (stack.peek() == '[') {
                        stack.pop();
                    }
                    else {
                        return false;
                    }
                }
                else {
                    stack.push(c);
                }
            }
        }
        if (stack.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
}
```
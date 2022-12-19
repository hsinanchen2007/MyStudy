### 解题思路
Stack存储左半边的括号，当出现右半边括号的时候去栈里pop一个看是否匹配，str全部遍历后均匹配则有效

### 代码

```java
class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
                continue;
            }

            if (c == ')' || c== ']' || c == '}') {

                if (stack.isEmpty()) {
                    return false;
                }

                char cache = stack.pop();

                if (isMatch(cache, c)) {
                    continue;
                }
                else {
                    return false;
                }
            }

        }

        if (!stack.isEmpty()) {
            return false;
        }

        return true;
    }

    private boolean isMatch(char a, char b) {

        if (a == '(') {
            return b == ')';
        }
        else if (a == '[') {
            return b == ']';
        }
        else if (a == '{') {
            return b == '}';
        }

        return false;
    }
}
```
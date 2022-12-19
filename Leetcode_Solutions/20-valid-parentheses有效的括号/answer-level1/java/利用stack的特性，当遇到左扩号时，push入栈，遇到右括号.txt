### 解题思路
注意当 当前 为右，且栈为空时，直接返回false


### 代码

```java
class Solution {
    // 利用stack 遇到 左，push，遇到右，与 栈顶比较，不相等，返回false
    public boolean isValid(String s) {
        int n = s.length();
        if (n % 2 == 1) return false;
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < n; i++) {
            if (isLeft(s.charAt(i))) {
                stack.push(s.charAt(i));
            //当前为右括号
            }else {
                //如果当前为右括号，且栈为空。返回 false
                if (stack.isEmpty()) {
                    return false;
                //当前为右括号，且栈不为空，如果不match 返回false    
                }else if (!match(stack.pop(), s.charAt(i))) {
                    return false;
                }
            }
        }

        return stack.isEmpty();
    }

    private boolean isLeft(char c) {
        return c == '(' || c == '[' || c == '{';
    }

    private boolean match(char ch1, char ch2) {

        return ch1 == '(' && ch2 == ')' ||
                ch1 == '{' && ch2 == '}' ||
                ch1 == '[' && ch2 == ']' ;
    }
}
```
### 解题思路
利用栈的特性，遇到特殊字符可进行后退

### 代码

```java
class Solution {
    public boolean backspaceCompare(String S, String T) {
        return build(S).equals(build(T));
    }
    public String build(String S){
        Stack<Character> stack = new Stack<>();
        for (char c : S.toCharArray()) {
            if ( c != '#') {
                stack.push(c);
            } else if (!stack.isEmpty() && c == '#') {
                stack.pop();
            }
        }
        return String.valueOf(stack);
    }
}
```
### 解题思路
遇到左括号入栈，右括号出栈。使用map存放左右括号映射，便于编程

### 代码

```java
class Solution {
    public boolean isValid(String s) {
        char[] chars = s.toCharArray();
        int length = chars.length;
        // 一定是偶数才可能true
        if((length & 1) == 1) {
            return false;
        }
        Map<Character, Character> map = new HashMap<>();
        map.put('[', ']');
        map.put('{', '}');
        map.put('(', ')');
        Stack<Character> stack = new Stack<>();
        // 遇到左括号入栈，右括号出栈即可
        for(int i = 0; i < length; i++) {
            if(chars[i] == '(' || chars[i] == '{' || chars[i] == '[') {
                stack.push(chars[i]);
            } else {
                if(stack.isEmpty()) {
                    return false;
                }
                char c = stack.peek();
                stack.pop();
                if(map.get(c) == chars[i]) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        if(stack.isEmpty()) {
            return true;
        }
        return false;
    }
}
```
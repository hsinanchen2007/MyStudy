### 解题思路
1. 注意入栈时机，遇到左括号
2. 注意出栈时机，非左即右
3. 不匹配立即返回，无需关注其他case
4. 边界校对
- 如果不是左括号，要先判断栈中是否有元素，没有表示匹配失败
- 如果遍历完字符串，栈为空，表示合法，否则不合法
最后，在进行这些操作前，一定要对入参进行校验！！！

### 代码

```java
class Solution {

    public boolean isValid(String s) {
        if (s == null || s.length() <= 0) return false;
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c); // 1
            } else {
                if (stack.isEmpty()) return false;
                char topChar = stack.pop(); // 2
                if (c == ')' && topChar != '(')
                    return false;
                if (c == ']' && topChar != '[')
                    return false;
                if (c == '}' && topChar != '{')
                    return false;
            }
        }
        return stack.isEmpty();
    }
}
```
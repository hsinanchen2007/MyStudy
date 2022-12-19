### 解题思路
此处撰写解题思路
此题关键还是character的运用，还要考虑当插入的字符串长度为技术时需要添加特殊字符代替，空栈判断

### 代码

```java
class Solution {
    public static boolean isValid(String s) {
        Map<Character,Character> map = new HashMap<Character,Character>();
        map.put(')','(');
        map.put('}','{');
        map.put(']','[');
        Stack<Character> stack = new Stack<Character>();
        for (int i = 0; i < s.length();i ++) {
            char c = s.charAt(i);
            if (map.containsKey(c)) {
                char topElement = stack.isEmpty() ? '&' : stack.pop();
                if (topElement != map.get(c)) {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }
        return stack.isEmpty();
    }
}
```
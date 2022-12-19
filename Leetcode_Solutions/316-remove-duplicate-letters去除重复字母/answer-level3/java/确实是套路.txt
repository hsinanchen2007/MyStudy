### 解题思路
题目做多了，就能透过现象看套路了，就行数学题一样，所以还得多刷题，没有太速成的办法。
### 代码

```java
class Solution {
    public String removeDuplicateLetters(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            Character ch = s.charAt(i);
            if (stack.contains(ch)) {
                continue;
            }
            while (!stack.isEmpty() && stack.peek() > ch && s.indexOf(stack.peek(), i) != -1) {
                stack.pop();
            }
            stack.push(ch);
        }
        char[] res = new char[stack.size()];
        for (int i = 0; i < stack.size(); i++) {
            res[i] = stack.get(i);
        }
        return new String(res);
    }
}
```
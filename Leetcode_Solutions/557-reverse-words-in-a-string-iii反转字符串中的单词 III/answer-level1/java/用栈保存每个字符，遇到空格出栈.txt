```java
class Solution {
    public String reverseWords(String s) {

        // 栈
        Stack<Character> stack = new Stack();
        // 保存结果
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            // 遇到空格了 -> 将栈中的元素出栈
            if (s.charAt(i) == ' ') {
                while (!stack.isEmpty()) {
                    sb.append(stack.pop());
                }
                sb.append(' ');
                continue;
            }

            // 不是空格 -> 入栈
            stack.push(s.charAt(i));
        }

        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }

        return sb.toString();
    }
}
```
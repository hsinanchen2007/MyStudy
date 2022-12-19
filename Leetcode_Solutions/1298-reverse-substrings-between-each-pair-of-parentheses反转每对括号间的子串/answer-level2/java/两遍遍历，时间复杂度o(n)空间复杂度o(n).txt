很多人的解法是，用栈存储当前括号内的字符串，遇到括号关闭，就直接反转字符串。

但是问题在于，字符串反转了多次，时间复杂度在最差的情况下可以达到o(n*n)

其实这题目完全可以通过两遍遍历来搞定的：

- 每个括号内部都算作独立的子问题
  - 如果正序，直接逐个append，逆序则反向append
  - 如果遇到括号，则继续分治。

代码：
```java
import java.util.Stack;

class Solution {
    private int[] parent;

    public String reverseParentheses(String s) {
        parent = new int[s.length()];
        Stack<Integer> stack = new Stack<Integer>();
        for (int i = 0; i < s.toCharArray().length; i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else if (s.charAt(i) == ')') {
                int f = stack.pop();
                parent[f] = i;
                parent[i] = f;
            }
        }
        StringBuilder sb = new StringBuilder(s.length());
        reverse(s, 0, s.length() - 1, false, sb);
        return sb.toString();
    }

    private void reverse(String s, int start, int end, boolean reversed, StringBuilder sb) {
        if (reversed) {
            for (int i = end; i >= start; i--) {
                if (s.charAt(i) == ')') {
                    reverse(s, parent[i] + 1, i - 1, false, sb);
                    i = parent[i];
                } else {
                    sb.append(s.charAt(i));
                }
            }
        } else {
            for (int i = start; i <= end; i++) {
                if (s.charAt(i) == '(') {
                    reverse(s, i + 1, parent[i] - 1, true, sb);
                    i = parent[i];
                } else {
                    sb.append(s.charAt(i));
                }
            }
        }
    }
}
```

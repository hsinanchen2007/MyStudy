### 解题思路
1. 从头至尾开始扫描每个字符串，然后使用一个栈来存储字符串；
2. 如果当前的字符串是'('，降其压入栈中；如果当前字符是')'并且栈顶的元素为'('的时候；我们就从栈中找到了满足括号配对的组合。否则我们就把')'压入栈中；
3. 扫描结束后，栈中只剩下了不满足配对的字符；相邻索引之间的子字符串则为最长有效括号；
4. 如果栈为空，那说明整个输入字符都是匹配的；否则重复步骤3；

### 代码

```java
class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length(), longest = 0;
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(')
                stack.push(i);
            else {
                if (!stack.empty()) {
                    if (s.charAt(stack.peek()) == '(')
                        stack.pop();
                    else
                        stack.push(i);
                } else
                    stack.push(i);
            }
        }
        if (stack.empty()) {
            longest = n;
        } else {
            int a = n, b = 0;
            while(!stack.empty()) {
                b = stack.peek();
                stack.pop();
                longest = Math.max(longest, a - b - 1);
                a = b;
            }
            longest = Math.max(longest, a);
        }
        return longest;
    }
}
```
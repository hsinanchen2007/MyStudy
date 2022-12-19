### 解题思路
我是用了两个栈，分别用来存储数字和符号，当遇到数字时将数字收集起来，当遇到其他字符时检查符号是否为']'如果不是将符号和数字分别入栈，当符号为']'时，数字弹出一位，符号弹出到遇见'['为止，将弹出的符号复制后入栈，字符串遍历完成后，再将栈中符号弹出整合，返回就是最终解码后的字符。

### 代码

```java
class Solution {
    public String decodeString(String s) {
        Stack<String> strStack = new Stack<>();
        Stack<Integer> numStack = new Stack<>();
        StringBuilder num = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c >= '0' && c <= '9') {
                num.append(c);
            } else if (c == ']') {
                int n = numStack.pop();
                String sb = popString(strStack);
                StringBuilder res = new StringBuilder();
                for (int i1 = 0; i1 < n; i1++) {
                    res.append(sb);
                }
                strStack.push(res.toString());
            } else {
                if (num.length() != 0) {
                    numStack.push(Integer.valueOf(num.toString()));
                    num = new StringBuilder();
                }
                strStack.push(String.valueOf(c));
            }
        }
        return popString(strStack);
    }
    private String popString(Stack<String> strStack) {
        StringBuilder sb = new StringBuilder();
        while (!strStack.empty()) {
            String s1 = strStack.pop();
            if ("[".equals(s1)) {
                break;
            }
            sb.insert(0, s1);
        }
        return sb.toString();
    }
}
```
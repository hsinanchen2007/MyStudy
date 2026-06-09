	基于栈结果实现
        1：遍历字符串，遇到 字符和"(" 括号入栈
        2：遇到")" 括号则遍历栈，取出该")" 括号对应的"(" 括号区间内所有的字符，按顺序出栈，用一个 stringbuild 保存起来
        3：将")" 括号对应的"(" 括号出栈消除，再将区间内的字符重新入栈，达到翻转一次的效果
        4：进行一次对栈的遍历，就完成字符串中括号对的消除，并将括号区间内的字符翻转一次重新入栈了
        5：最后将栈中全部字符出栈，反转输出即为所求

```
    public static String reverseParentheses(String s) {
        Stack<Character> stack = new Stack<>();
        StringBuilder result = new StringBuilder();
        char[] chars = s.toCharArray();
        for (int i = 0; i < chars.length; ++i) {
            if (chars[i] == ')') {
                StringBuilder sb = new StringBuilder();
                while (!stack.isEmpty() && stack.peek() != '(') {
                    sb.append(stack.pop());
                }
                stack.pop();// 将')'对应的'('消除
                char[] c1 = sb.toString().toCharArray();
                for (char c : c1) {
                    stack.add(c);
                }
            } else {
                stack.push(chars[i]);
            }
        }
        while (!stack.isEmpty()) {
            result.append(stack.pop());
        }
        return result.reverse().toString();
    }
```

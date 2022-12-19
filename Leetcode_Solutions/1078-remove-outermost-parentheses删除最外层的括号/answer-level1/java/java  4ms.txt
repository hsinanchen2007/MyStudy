1)借助栈,9ms
```
 LinkedList<Character> stack = new LinkedList<>();
        StringBuilder res = new StringBuilder();
        for (char c : S.toCharArray()) {
            if (c == '(') {
                if (!stack.isEmpty()) {
                    res.append(c);
                }
                stack.add(c);
            } else if (c == ')') {
                stack.removeLast();
                if (!stack.isEmpty()) res.append(c);
            } else {
                res.append(c);
            }
        }
        return res.toString();
```
2)4ms,由上面可以看出,栈的作用只是用来判断当前'('是否是第一个左括号以及当前')'是否匹配第一个左括号,所以仍然可以加以优化
```
    public String removeOuterParentheses(String S) {
        StringBuilder res = new StringBuilder();
        int flag = 0;
        for (char c : S.toCharArray()) {
            if (c == '(') {
                if (flag != 0) {
                    res.append(c);
                }
                flag++;
            } else if (c == ')') {
                flag--;
                if (flag != 0) res.append(c);
            } else {
                res.append(c);
            }
        }
        return res.toString();

    }
```

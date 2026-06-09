思路：如果遇到t或者f，直接返回true或者false。
从左到右遍历表达式，遇到逗号直接跳过，遇到非右括号的字符压到栈里，遇到右括号则弹出栈里的元素直至左括号弹出，然后再弹出一个元素，最后弹出的元素（弹出左括号之后弹出的元素）一定是运算符。
对于弹出的元素，根据t和f的数量以及运算符判断运算结果是t或者f，将新的运算结果压到栈里。直到栈里只剩一个元素，这个元素一定是t或者f，根据该元素的值返回结果。

```
class Solution {
    public boolean parseBoolExpr(String expression) {
        if (expression.equals("t"))
            return true;
        else if (expression.equals("f"))
            return false;
        Stack<Character> stack = new Stack<Character>();
        char[] array = expression.toCharArray();
        int length = array.length;
        for (int i = 0; i < length; i++) {
            char c = array[i];
            if (c == ',')
                continue;
            else if (c != ')')
                stack.push(c);
            else {
                int tCount = 0, fCount = 0;
                while (stack.peek() != '(') {
                    char val = stack.pop();
                    if (val == 't')
                        tCount++;
                    else if (val == 'f')
                        fCount++;
                }
                stack.pop();
                char op = stack.pop();
                char nextVal = 'u';
                if (op == '&') {
                    if (fCount == 0)
                        nextVal = 't';
                    else
                        nextVal = 'f';
                } else if (op == '|') {
                    if (tCount > 0)
                        nextVal = 't';
                    else
                        nextVal = 'f';
                } else if (op == '!') {
                    if (tCount == 1)
                        nextVal = 'f';
                    else
                        nextVal = 't';
                }
                stack.push(nextVal);
            }
        }
        char lastChar = stack.pop();
        boolean res = (lastChar == 't' ? true : false);
        return res;
    }
}
```

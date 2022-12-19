### 解题思路
12 ms	39.5 MB
改了点大佬的东西 先去空格  把*/算完入栈 加起来

### 代码

```java
class Solution {
    public static int calculate(String s) {
        s = s.replace(" ", "");
        Stack<Integer> stack = new Stack();
        char oper = '+';
        int num = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (!isOper(c)) {
                num = num * 10 + (c - '0');
            }
            if (isOper(c) || i == n - 1) {
                int pre;
                switch (oper) {

                    case '+':
                        stack.push(num);
                        break;
                    case '-':
                        stack.push(-num);
                        break;
                    case '*':
                        pre = stack.pop();
                        stack.push(pre * num);
                        break;
                    case '/':
                        pre = stack.pop();
                        stack.push(pre / num);
                        break;
                }
                oper = c;
                num = 0;
            }

        }
        int res = 0;
        while (!stack.isEmpty()) {
            res += stack.pop();
        }
        return res;
    }
    //符号为tru 数字为false
    public static boolean isOper(char s) {
        return s == '+' || s == '-' || s == '*' || s == '/';
    }
}

```
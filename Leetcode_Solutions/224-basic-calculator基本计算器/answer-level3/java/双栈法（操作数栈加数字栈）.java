思路： 如果题目输入字符串是逆波兰表达式，那这个题就很简单了。直接采用一个栈即可，遇到操作符就计算，遇到右括号，就将里面的串计算完成后，再和左括号成对的退出。但是这道题 ，它不是逆波兰表达式，它是一个用户友好的表达式。 这样我们就需要用别的解法了。

一个很直观的思维就是， 把操作符和数字分开存到两个栈中，需要计算的时候，从数字栈中弹出两个数字，从操作数栈中弹出一个元素，计算完成后再放入数字栈中。
代码如下：

```
/**
     * 双栈法 -- 个人感觉最简单
     * @param s
     * @return
     */
    public static int calculate(String s) {
        if (s == null || s.length() == 0) {
            return -1;
        }
        // 操作数栈，遇到+,-和(, 就入栈
        Stack<Character> operatorStack = new Stack<>();

        // 数字栈，遇到数字放入
        Stack<Integer> digitStack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            // 为空格直接跳过
            if (c == ' ') {
                continue;
            }
            // 如果是正括号或者加减号，则直接入栈
            if (c == '(' || c == '+' || c == '-') {
                operatorStack.push(c);
            } else if (c == ')') {
                // 开始弹出并计算
                operatorStack.pop();
                // 触发连续计算。 如果操作符栈顶有+或-，则弹出计算，计算完成后，放到digitStack中
                while (operatorStack.size() > 0 && isOperator(operatorStack.peek())) {
                    int b = digitStack.pop();
                    int a = digitStack.pop();
                    digitStack.push(calc(a, b, operatorStack.pop()));
                }
            } else {
                // 数字，求最长连续数字串
                int digitTotal = 0;
                int j = i;
                for (; j < s.length(); j++) {
                    char tmpChar = s.charAt(j);
                    if (isDigit(tmpChar)) {
                        digitTotal = 10 * digitTotal + (tmpChar - '0');
                    } else {
                        break;
                    }
                }
                // 判断是否要计算一波。如果操作数栈为空或者栈顶不为+或-，则直接数字入栈
                if (operatorStack.isEmpty() || !isOperator(operatorStack.peek())) {
                    digitStack.push(digitTotal);
                }
                // 如果操作符栈顶有+或-，则弹出计算，计算完成后，放到digitStack中
                while (operatorStack.size() > 0 && isOperator(operatorStack.peek())) {
                    Character cc = operatorStack.pop();
                    Integer d = digitStack.pop();
                    digitStack.push(calc(d, digitTotal, cc));
                }
                i = j - 1;
            }
        }
        // 返回数字栈顶元素，即为结果
        return digitStack.pop();
    }

    private static int calc(int a, int b, char op) {
        if (op == '+') {
            return a + b;
        } else {
            return a - b;
        }
    }

    private static boolean isDigit(char c) {
        return c >= '0' && c <= '9';
    }
    private static boolean isOperator(char c) {
        return c == '+' || c == '-';
    }
```

**超好理解，请看代码和注释**
```
class Solution {
    public int calculate(String s) {
        Stack<Integer> numStack = new Stack<>();
        Stack<Character> operStack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            // 如果是空格则跳过
            if (c == ' ') {
                continue;
            } else if (isOper(c)) {
                // 如果运算符号栈为空则直接入栈
                if (operStack.size() == 0) {
                    operStack.push(c);
                } else if (c == ')') {
                    // 如果是')'则 在数字栈弹出两个数 在运算符号栈弹出一个符号
                    // 进行运算 结果压入数字栈中
                    // 如果一直没遇到'(' 则重复上面过程 直到遇到'('
                    while (operStack.peek() != '(') {
                        int num1 = numStack.pop();
                        int num2 = numStack.pop();
                        char oper = operStack.pop();
                        int res = cal(num1, num2, oper);
                        numStack.push(res);
                    }
                    // 将'('弹出运算符号栈
                    operStack.pop();
                } else if (operStack.peek() == '(') {
                    // 如果栈顶是'(' 则运算符号直接入栈
                    operStack.push(c);
                } else if (weight(c) <= weight(operStack.peek())) {
                    // 如果运算符号栈顶不是'(' 且当前符号优先级没有栈顶符号优先级高
                    // 则弹出两个数和一个运算符 进行计算
                    // 将计算结果和当前运算符压入栈中
                    int num1 = numStack.pop();
                    int num2 = numStack.pop();
                    char oper = operStack.pop();
                    int res = cal(num1, num2, oper);
                    numStack.push(res);
                    operStack.push(c);
                } else {
                    // 其他情况：当前符号优先级比栈顶符号优先级高
                    // 直接入栈
                    operStack.push(c);
                }
            } else {
                // 用于处理多位数情况
                StringBuilder sb = new StringBuilder();
                sb.append(s.charAt(i));
                // 得到最长连续数字串
                while (i != s.length() - 1 && s.charAt(i + 1) != ' ' && !isOper(s.charAt(i + 1))) {
                    sb.append(s.charAt(i + 1));
                    i++;
                }
                int num = Integer.parseInt(sb.toString());
                numStack.push(num);
            }
        }
        // 不断从数字栈中弹出两个数 从运算符号栈中弹出一个符号
        // 进行计算 并将结果压回栈中 知道数字栈中只有一个数字
        while (numStack.size() > 1) {
            Integer num1 = numStack.pop();
            Integer num2 = numStack.pop();
            Character oper = operStack.pop();
            int res = cal(num1, num2, oper);
            numStack.push(res);
        }
        // 返回数字栈中唯一的数字 就是计算结果
        return numStack.peek();
    }

    /**
     * 获取运算符号的优先级
     *
     * @param o 运算符号
     * @return 运算符号的优先级
     */
    public int weight(char o) {
        if (o == '+' || o == '-') {
            return 0;
        } else {
            return -1;
        }
    }

    /**
     * 传入两个数一个运算符号进行计算
     *
     * @param num1 先从栈中弹出的数
     * @param num2 后从栈中弹出的数
     * @param oper 运算符
     * @return 计算后的结果
     */
    public int cal(int num1, int num2, char oper) {
        if (oper == '+') {
            return num2 + num1;
        } else {
            return num2 - num1;
        }
    }

    /**
     * 判断是不是运算符
     *
     * @param c 需要判断的字符
     * @return 如果是运算符返回true 否则返回false
     */
    public boolean isOper(char c) {
        if (c == '+' || c == '-' || c == '(' || c == ')') {
            return true;
        }
        return false;
    }
}
```

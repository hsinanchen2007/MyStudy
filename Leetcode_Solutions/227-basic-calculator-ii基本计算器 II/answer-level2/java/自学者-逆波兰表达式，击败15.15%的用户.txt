### 解题思路
* 先用列表记录逆波兰表达式内容
* 字符转多位数字算法

### 代码

```java
class Solution {
    public int calculate(String formula) {
        int result = 0;
        Stack<String> operatorStack = new Stack<>();
        List<String> rpnList = new ArrayList<>();
        int i = 0;
        int len = formula.length();
        int curOperand = Integer.MIN_VALUE;
        //assemble the infix expression
        while (i < len) {
            char currentChar = formula.charAt(i);
            if (currentChar == ' ' || currentChar == ',') {
                // 过滤空格，MIN or MAX函数中的逗号自动掠过
                i++;
                continue;
            }
            if (Character.isDigit(currentChar)) {
                if (curOperand == Integer.MIN_VALUE) {
                    curOperand = Character.getNumericValue(currentChar);
                } else {
                    curOperand = curOperand * 10 + Character.getNumericValue(currentChar);
                }
                i++;
            } else {
                if (curOperand != Integer.MIN_VALUE) {
                    rpnList.add(Integer.toString(curOperand));
                    curOperand = Integer.MIN_VALUE;
                }
                // + - * / 四个运算符按照优先级进行逆波兰表达式
                if (isOperator(currentChar)) {
                    String operator = currentChar + "";
                    String topOperator;
                    while (!operatorStack.isEmpty() && priority(operatorStack.peek()) >= priority(operator)) {
                        topOperator = operatorStack.pop();
                        rpnList.add(topOperator);
                    }
                    operatorStack.push(operator);
                    i++;
                } else if (currentChar == '(') {
                    //Left parenthesis: Push it into stack.
                    operatorStack.push(currentChar + "");
                    i++;
                } else if (currentChar == ')') {
                    String cur;
                    while (!operatorStack.isEmpty()) {
                        cur = operatorStack.peek();
                        if (cur.equals("(")) {
                            //当前算法不包含容错处理，确保每个表达式都是正确的，一定会碰到左括号
                            operatorStack.pop();
                            break;
                        } else {
                            operatorStack.pop();
                            rpnList.add(cur);
                        }
                    }
                    i++;
                }
            }
        }
        if (curOperand != Integer.MIN_VALUE) {
            rpnList.add(Integer.toString(curOperand));
        }
        //最后弹出栈内所有剩余元素
        while (!operatorStack.isEmpty()) {
            rpnList.add(operatorStack.pop());
        }
        // System.out.println(rpnList.toString());
        String[] objects = rpnList.toArray(new String[rpnList.size()]);
        result = evalRPN(objects);
        return result;
    }

    public static int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        for (String s : tokens) {
            if (s.equals("+")) {
                stack.push(stack.pop() + stack.pop());
            } else if (s.equals("-")) {
                stack.push(-stack.pop() + stack.pop());
            } else if (s.equals("*")) {
                stack.push(stack.pop() * stack.pop());
            } else if (s.equals("/")) {
                int num1 = stack.pop();
                stack.push(stack.pop() / num1);
            } else {
                stack.push(Integer.parseInt(s));
            }
        }
        return stack.pop();
    }

    private static int priority(String operator) {
        switch (operator) {
            case "+":
            case "-":
                return 1;
            case "*":
            case "/":
                return 2;
            default:
                return 0;
        }
    }

    private static boolean isOperator(char ch) {
        switch (ch) {
            case '+':
            case '-':
            case '*':
            case '/':
                return true;
            default:
                return false;
        }
    }
}
```
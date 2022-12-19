思路：
1. 顺序遍历运算表达式中每个字符，并压入字符栈（遇到","时跳过，不入栈），在入栈时，如果遇到右括号，则做局部运算。
2. 局部运算结果再压入栈，那么遍历到最后右括号，局部运算计算完成后，栈中只保留一个字符，即为结果。


```java []
public class Solution {
    public boolean parseBoolExpr(String expression) {
        Stack<Character> worker = new Stack<>();
        for (int i = 0; i < expression.length(); i++) {
            char currentChar = expression.charAt(i);
            Stack<Character> operTemp = new Stack<>();
            if (currentChar == ',') {
                continue;
            }
            if (currentChar != ')') {
                worker.push(currentChar);
            } else {
                while (worker.peek() != '(') {
                    operTemp.push(worker.pop());
                }
                worker.pop();
                char oper = worker.pop();
                Character blockResult = blockExpr(operTemp, oper);
                if (blockResult == null) {
                    System.out.println("运算符输入有误,结果不可信");
                    return false;
                }
                worker.push(blockResult);
            }
        }
        return worker.pop() == 't';
    }

    public Character blockExpr(Stack<Character> operStack, char oper) {
        if (oper == '!') {
            return operStack.pop() == 't' ? 'f' : 't';
        }
        if (oper == '&') {
            while (!operStack.isEmpty()) {
                if (operStack.pop() == 'f') {
                    return 'f';
                }
            }
            return 't';
        }
        if (oper == '|') {
            while (!operStack.isEmpty()) {
                if (operStack.pop() == 't') {
                    return 't';
                }
            }
            return 'f';
        }
        return null;
    }
}
```


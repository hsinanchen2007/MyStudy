用了两个栈，一个操作符栈，一个操作数栈。然后开始循环：
1.遇到t、f和左括号入操作数栈。
2.遇到|、&和!入操作符栈
3.遇到逗号不处理
4.遇到右括号时，将操作数栈中的元素依次出栈，直到遇到左括号停止，再从操作符栈中出栈一个操作符。计算出栈的操作数根据出栈的操作符的运算结果，并将运算结果入操作数栈。
最后栈中只剩一个元素，就是结果

```
public boolean parseBoolExpr(String expression) {
    ArrayDeque<Character> stackOperand = new ArrayDeque<>();
    ArrayDeque<Character> stackOperator = new ArrayDeque<>();
    char[] chars = expression.toCharArray();
    for (int i = 0; i < chars.length; i++) {
        if (chars[i] == 't' || chars[i] == 'f' || chars[i] == '(') {
            stackOperand.push(chars[i]);
        } else if (chars[i] == '|' || chars[i] == '&' || chars[i] == '!') {
            stackOperator.push(chars[i]);
        } else if (chars[i] == ')') {
            int trueCount = 0;
            int falseCount = 0;
            while (!stackOperand.isEmpty()) {
                char pop = stackOperand.pop();
                if (pop == 't') {
                    trueCount++;
                } else if (pop == 'f') {
                    falseCount++;
                } else if (pop == '(') {
                    break;
                }
            }
            char operator = stackOperator.pop();
            if (operator == '!') {
                stackOperand.push(trueCount == 0 ? 't' : 'f');
            } else if (operator == '&') {
                stackOperand.push(falseCount > 0 ? 'f' : 't');
            } else if (operator == '|') {
                stackOperand.push(trueCount > 0 ? 't' : 'f');
            }
        }
    }
    return stackOperand.pop() == 't' ? true : false;
}
```

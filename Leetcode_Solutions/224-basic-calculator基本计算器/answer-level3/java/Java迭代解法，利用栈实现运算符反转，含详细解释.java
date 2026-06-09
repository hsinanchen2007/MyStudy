这题只要解决了括号的问题就很简单了。再加上本题有个限定条件是只有加和减两种操作，所以在处理括号时只需要考虑括号前的符号：

- 如果`(`前是`-`，那么反转括号内的所有运算符（+变成-，-变成+）
- 如果`(`前是`+`，则不需要反转括号内的运算符
- 遇到`)`时，恢复成上一层级的反转规则

用一个栈来保存当前的运算符反转规则，true代表反转，false代表不反转，栈为空时也不反转

以`1-(2-(3+4)-5)+6`为例说明：
- 第一个`(`前的运算符是`-`，将反转规则`true`入栈，栈内容`[true]`，已处理的算式为`1-2`
- 下一个运算符是`-`，而当前栈顶元素为`true`，故将其反转，此时已处理的算式为`1-2+`
- 第二个`(`前的运算符是`+`（刚刚反转的），故将反转规则`false`入栈，栈内容`[false,true]`，已处理的算式为`1-2+3`
- 下一个运算符是`+`，当前栈顶元素为`false`，不需要反转，已处理的算式为`1-2+3+4`
- 遇到`)`，将栈顶元素弹出，栈内容`[true]`，下一个运算符为`-`，根据当前栈顶元素，需要进行反转，已处理的算式为`1-2+3+4+5`
- 再次遇到`)`，将栈顶元素弹出，此时栈为空
- 下一个运算符是`+`，此时栈为空，不需要反转，最终处理完成的算式为`1-2+3+4+5+6`
- 现在算式中已经没有括号，直接进行运算即可得出最终结果`17`

运算符的处理和运算可以在一趟迭代中完成，故算法时间复杂度为O(N)。需要一个栈来保存括号前的运算符，实际使用的辅助空间取决于算式内括号的层数，极限的辅助空间为O(N)

代码耗时10ms

代码：
```java []
class Solution {
    public int calculate(String s) {
        LinkedList<Boolean> stack = new LinkedList<>();
        int result = 0, opr = 0; //result: 当前的结果值; opr: 当前的被加/被减数
        Character op = null; //当前要执行的运算符
        for (char c : s.toCharArray()) {
            if (c == '+' || c == '-') {
                if (op == null) {
                    //遇到第一个运算符时，将result置为opr（即第一个运算符左边的数字）
                    result = opr;
                } else {
                    //result = result +/- opr;
                    result = cal(op, result, opr);
                }
                //根据栈顶元素决定是否反转运算符
                op = swap(stack.peek() == null ? false : stack.peek(), c);
                opr = 0;
            } else if (c == '(') {
                stack.push(op != null && op == '-');
            } else if (c == ')') {
                stack.pop();
            } else if (c != ' ') {
                opr = opr * 10 + c - '0';
            }
        }
        if (op == null) {
            //算式中没有运算符时，opr就是最终结果
            return opr;
        } else {
            //否则将result与opr（即算式中最右边的数字）执行一次运算
            return cal(op, result, opr);
        }
    }

    char swap(boolean swap, char c) {
        if (swap) {
            return c == '+' ? '-' : '+';
        } else {
            return c;
        }
    }

    private int cal(char op, int opr1, int opr2) {
        switch (op) {
            case '+':
            return opr1 + opr2;
            case '-':
            return opr1 - opr2;
            default:
            return 0;
        }
    }
}
```

在【基本计算器II】的基础上，我们可以用递归的方法将括号中的运算作为参数传入，直接做递归运算，这是最为方便快捷的做法。此外，我们也可以不使用递归，防止括号过多的情况下函数栈溢出。

相比于【基本计算器II】，我们需要额外考虑的只有括号的处理，其他操作都基本相同。在解题之前，我们可以分析出一个规律：'('前面一定不是数字，而其他符号前面一定是数字。

因此，遇到'('符号，我们可以把它前面的符号压入栈中做个标记，在处理完括号里的运算后，再回头做对应的运算。遇到')'符号时，我们需要先将栈顶的所有数字累加，直到栈顶变成运算符字符串为止。此时意味着我们已经把这对括号内的运算都处理完了，得到了括号内的运算结果。将栈顶的运算符取出后，我们对括号的结果进行对应的运算就可以了。

Python实现的代码如下：

```python []
from collections import deque

class Solution:
    # Deal with the operations
    def solve(self, operand: int, sign: str, stack: deque) -> int:
        if sign == '+':
            return operand
        elif sign == '-':
            return -operand
        elif sign == '*':
            return stack.pop() * operand
        elif sign == '/':
            return int(stack.pop() / operand)

    def calculate(self, s: str) -> int:
        stack = deque()

        operand = 0
        sign = '+'

        for c in s:
            if c == ' ':
                # Ignore the space
                continue
            elif c.isdigit():
                operand = operand * 10 + int(c)
            elif c == '(':
                # An integer cannot be just before a '(', so only save the previous operator here
                stack.append(sign)
                sign = '+'
            else:
                # Do the default calculation
                result = self.solve(operand, sign, stack)

                operand = 0

                if c == ')':
                    # Summate all the intergers on the top of a stack until meet an operator, which means
                    # we need to do the corresponding operation with the summation value as an operand
                    while isinstance(stack[-1], int):
                        result += stack.pop()

                    sign = stack.pop()

                    operand = self.solve(result, sign, stack)
                    sign = '+'
                else:
                    # Push the result value to the stack for later summation
                    # Save the operator for calculation in a coming loop
                    sign = c
                    stack.append(result)

        # The calculation doesn't finish here. We always do actual calculation in later loops, so
        # at present we should deal with the operand gotten in the last loop.
        last = self.solve(operand, sign, stack)
        stack.append(last)

        # + and - have the lowest priority
        return sum(stack)

```

在这样的解法中，运算时间约和字符串长度 N 成正比，复杂度为 O(N)；需要的栈长度不超过字符串中运算符的数量，小于 N/2，复杂度为 O(N)。


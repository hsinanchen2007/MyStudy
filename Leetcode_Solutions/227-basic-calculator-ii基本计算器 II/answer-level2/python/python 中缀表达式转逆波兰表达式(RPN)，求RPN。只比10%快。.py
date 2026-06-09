```
OPT = {'+', '-', '*', '/'}


def cmp_opt(op1, op2):
    if op1 in ('*', '/') and op2 in ('+', '-'):
        return 1
    return -1
    # elif op1 in ('-', '+') and op2 in ('*', '/'):
        # return -1
    # return -1


class Reader(object):
    def __init__(self, cs):
        self.cs = cs
        self.i = 0

    def read_a_item(self):
        try:
            if self.cs[self.i] in OPT:
                self.i += 1
                return self.cs[self.i - 1]
            else:
                i = self.i
                while self.cs[i] not in OPT:
                    i += 1
                    if i >= len(self.cs):
                        break
                rev = int(''.join(self.cs[self.i:i]))
                self.i = i
                return rev
        except IndexError:
            return None

    def read(self):
        a = []
        c = self.read_a_item()
        while c is not None:
            a.append(c)
            c = self.read_a_item()
        return a


def toRPN(s):
    op_stack = []
    num_stack = []

    reader = Reader(list(s.replace(' ', '')))

    cs = reader.read()
    for c in cs:
        if c not in OPT:
            num_stack.append(c)
        else:
            if op_stack:
                while op_stack:
                    if cmp_opt(c, op_stack[-1]) < 0:
                        num_stack.append(op_stack.pop())
                    else:
                        op_stack.append(c)
                        break
                else:
                    op_stack.append(c)
            else:
                op_stack.append(c)

    while op_stack:
        num_stack.append(op_stack.pop())

    return num_stack

def evalRPN(tokens):
    """
    :type tokens: List[str]
    :rtype: int
    """
    fd = {'+': int.__add__, '*': int.__mul__, '-': int.__sub__,
          '/': int.__div__}

    stack = []
    for t in tokens:
        if t in ('+', '-', '*', '/'):
            a1 = stack.pop()
            a2 = stack.pop()
            stack.append(fd[t](a2, a1))
        else:
            stack.append(int(t))
    return int(stack[-1])


class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        return evalRPN(toRPN(s))
```
toRPN用来把表达式编程RPN。借助Reader用来把字符串变成 数字或者表达式 组成的列表。cmp_opt在toRPN的时候帮忙比较操作符的顺序。
evalRPN计算RPN的值。


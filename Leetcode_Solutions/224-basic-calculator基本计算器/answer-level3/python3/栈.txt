## 思路:

栈

把括号里先算出来，

最好表达是用代码展现出来， 直接看代码！

两种写法， 第一种好理解， 第二种简介！

------

如有疑惑， 欢迎留言~

相关链接： [227. 基本计算器 II](https://leetcode-cn.com/problems/basic-calculator-ii/)

## 代码:

第一种

```python
class Solution:
    def calculate(self, s: str) -> int:
        res = 0
        stack = []
        sign = 1
        i = 0
        n = len(s)
        while i < n:
            if s[i] == " ":
                i += 1
            elif s[i] == "-":
                sign = -1
                i += 1
            elif s[i] == "+":
                sign = 1
                i += 1
            elif s[i] == "(":
                stack.append(res)
                stack.append(sign)
                res = 0
                sign = 1
                i += 1
            elif s[i] == ")":
                # print(stack)
                res = res * stack.pop() + stack.pop()
                i += 1
            elif s[i].isdigit():
                tmp = int(s[i])
                i += 1
                while i < n and s[i].isdigit():
                    tmp = tmp * 10 + int(s[i])
                    i += 1
                res += tmp * sign
        return res
```

第二种

```python
class Solution:
    def calculate(self, s: str) -> int:
        stack = []
        # 记录数字的符号, 因为题目说没有负数,说明第一个为正数,设为1
        sign = 1
        # 数字
        num = 0
        # 结果
        res = 0
        for c in s:
            if c.isdigit():
                num = num * 10 + int(c)
            elif c == "+":
                res += sign * num
                # 为下一次做准备
                num = 0
                sign = 1
            elif c == "-":
                res += sign * num
                # 为下一次做准备
                num = 0
                sign = -1
            elif c == "(":
                stack.append(res)
                stack.append(sign)
                sign = 1
                res = 0
            elif c == ")":
                res += sign * num
                num = 0
                res = stack.pop() * res + stack.pop()
        res += sign * num
        return res
```




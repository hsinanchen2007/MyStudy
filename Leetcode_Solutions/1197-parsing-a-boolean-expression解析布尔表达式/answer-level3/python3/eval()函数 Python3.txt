**思路：**

本题正常做法应该用栈或者递归，记录每一层的运算符，运算后的结果返回给上一层。不过在Python中，我们可以有个偷懒的办法，利用`eval()`函数来帮我们计算布尔表达式的值。在遍历表达式的过程中，我们还是需要一个变量`level`来记录当前是第几层表达式，每当遇到左括号`(`，`level`就加1，遇到右括号`)`，`level`就减一。遇到运算符`!`、`&`或`|`时，我们将其替换为Python中的`not`、`and`和`or`，并记录下来，遇到该层内的逗号`,`时，我们就把逗号替换成该层的运算符。遇到`f`替换为`False`，遇到`t`替换为`True`。最后用`eval()`函数计算整个替换后的表达式。
如果把`&`和`|`换成`all`和`any`函数的话，还可以有一行代码解决的写法，不过要对函数声明加两个默认参数。

**代码：**

```python []
class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        level = 0
        sign = [""]
        exp = []
        for e in expression:
            if e == "!":
                sign[level] = " not "
                exp.append(" not ")
            if e == "&":
                sign[level] = " and "
            if e == "|":
                sign[level] = " or "
            if e == "(":
                sign.append("")
                level += 1
                exp.append("(")
            if e == ")":
                level -= 1
                exp.append(")")
            if e == ",":
                exp.append(sign[level - 1])
            if e == "f":
                exp.append("False")
            if e == "t":
                exp.append("True")
        return eval(''.join(exp))
```
```python []
# 一行写法，需要对函数声明做一些改动，用默认参数
class Solution:
    def parseBoolExpr(self, S: str, t=True, f=False) -> bool:
        return eval(S.replace('!', 'not |').replace('&(', 'all([').replace('|(', 'any([').replace(')', '])'))
```
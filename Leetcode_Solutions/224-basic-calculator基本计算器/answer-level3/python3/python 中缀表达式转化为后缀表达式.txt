## 224. 基本计算器

思路： 先将中缀表达式转化为后缀表达式，然后再根据LC150根据后缀表计算得到结果。

中缀表达式转换为后缀表达式思路：（参考大话数据结构——大话设计模式）

规则：从左到右遍历中缀表达式的每个数字和符号，若是数字就输出，即成为后缀表达式的一部分；若是符号，则判断其与栈顶符号的优先级，是右括号或优先级不高于栈顶符号（乘除优先加减）则栈顶元素依次出栈并输出，并将当前符号出栈，一直到最终输出后缀表达式为止。

前：prefix expression

中：infix expression

后：suffix expression

re.split('(\W)', s) 可以进行拆分

```
class Solution:
    def calculate(self, s: str) -> int:
        tokens = self.infix_to_suffix(s)
        result = self.evalRPN(tokens)
        return result
            
    def infix_to_suffix(self,s):
        s = re.split('(\W)',s)
        result = []
        stack = []
        op_priority = {'*':2,
                      '/':2,
                      '%':2,
                      '+':1,
                      '-':1}
        for i in s:
            if i == '' or i == ' ':
                continue
            if i == '(':
                stack.append(i)
            elif i == ')':
                while stack[-1] != '(':
                    result.append(stack.pop())
                stack.pop()
            elif i in op_priority.keys():
                while stack and stack[-1] in op_priority.keys() and op_priority[i] <= op_priority[stack[-1]]:
                    result.append(stack.pop())
                stack.append(i)
            else:
                result.append(int(i))
        while stack:
            result.append(stack.pop())
        return result
    
    def evalRPN(self, tokens):
        f1 = lambda a,b:a+b
        f2 = lambda a,b: a - b
        f3 = lambda a,b: a*b
        f4 = lambda a,b: int(a/b)
        maps = {'+':f1,'-':f2,'*':f3,'/':f4}
        stack = []
        for token in tokens:
            if token in maps:
                a = stack.pop()
                b = stack.pop()
                stack.append(maps[token](b,a))
            else:
                token = int(token)
                stack.append(token)
        return stack[-1] 
```

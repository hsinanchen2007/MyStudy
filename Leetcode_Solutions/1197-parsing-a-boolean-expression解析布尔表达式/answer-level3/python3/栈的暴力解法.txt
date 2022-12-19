详见代码注释
```
class Solution(object):#stack暴力解法
    def parseBoolExpr(self, expression):
        stack = []  # 用来储存所有的东西
        temp = []  # 用来在发现')'后来储存True和False
        for i in range(len(expression)):
            if expression[i] == ',':
                continue
            elif expression[i] == ')':  # 如果')'出现了，关键的操作部分开始
                while stack and stack[-1] != '(':
                    temp.append(stack.pop())
                stack.pop()
                now = temp[0]
                if stack[-1] == '!':  # 如果是否那么直接把not now放入stack
                    stack.pop()
                    stack.append((not now))
                else:
                    for i in range(1, len(temp)):  # 如果是另外两种，那么把temp里的元素诸葛比对后再把结果放入stack
                        if stack[-1] == '|':
                            now = now or temp[i]
                        elif stack[-1] == '&':
                            now = now and temp[i]
                    stack.pop()
                    stack.append(now)
                temp = []
            elif expression[i] == 't':  # 't','f','('只需要常规的入栈即可
                stack.append(True)
            elif expression[i] == 'f':
                stack.append(False)
            else:
                stack.append(expression[i])
        return stack[-1]
```

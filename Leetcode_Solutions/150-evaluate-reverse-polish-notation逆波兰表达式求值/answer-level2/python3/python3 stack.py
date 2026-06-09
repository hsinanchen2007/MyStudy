
6//-123会变成-1。。。只能 int(6/-123)

执行用时：40 ms 内存消耗：13.6 MB
```
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack=[]
        for e in tokens:
            if e == "+":
                stack.append(stack.pop()+stack.pop())
            elif e == "-":
                stack.append(-stack.pop()+stack.pop())
            elif e == "*":
                stack.append(stack.pop()*stack.pop())
            elif e == "/":
                n = stack.pop()
                m = stack.pop()
                stack.append(int(m/n))
            else:
                stack.append(int(e))
        return stack[0]
```

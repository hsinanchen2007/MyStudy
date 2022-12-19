
```python3
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        if len(tokens)==1:
            return int(tokens[0])
        stack = []
        tem = ['+','-','*','/']
        for i in tokens:
            if len(stack)<2 and i not in tem:
                stack.append(int(i))
            elif i not in tem:
                stack.append(int(i))
            else:
                p1 = stack.pop()
                p2 = stack.pop()
                if i=='+':
                    result = p1+p2
                elif i=='-':
                    result = p2-p1
                elif i=='/':
                    result = int(p2/p1) #注意不能用//，负数的时候会出错
                elif i =='*':
                    result = p1*p2
                stack.append(result)
        return result
            
```
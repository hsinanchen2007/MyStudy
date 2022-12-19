好吧就是用个栈，一看就会：
```
class Solution:
    
    def evalRPN(self, tokens: List[str]) -> int:
        
        stack = []
        
        for i in tokens:
            
            if i in '+-*/': ## 比起别的python题解，这句是唯一的亮点
                
                a = stack.pop()
                b = stack.pop()
                c = str(int(eval(b+i+a)))
                stack.append(c)
                
            else:
                
                stack.append(i)
                
        return stack[0]
```
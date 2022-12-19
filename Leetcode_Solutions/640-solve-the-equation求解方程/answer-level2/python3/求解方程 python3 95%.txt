> 简单思路
```python
import math
class Solution:
    def solveEquation(self, equation: str) -> str:
        
        def get_ab(equation):
            equation = equation + '#'
            a,b = 0,0
            stack = []
            flag = True
            flag1 = -1 if equation[0] == '-' else 1
            if equation[0] == '-':
                equation = equation[1:]
            for i in equation:
                if i in '-+#':
                    if flag:
                        b += flag1*int(''.join(stack))
                    else:
                        if not stack:
                            a += flag1
                        else:
                            a += flag1*int(''.join(stack))
                    flag = True
                    flag1 = -1 if i == '-' else 1
                    stack = []
                elif i in '0123456789':
                    stack.append(i)
                else:
                    flag = False
            return a,b
                    
        e1,e2 = equation.split('=')
        e1 = get_ab(e1)
        e2 = get_ab(e2)
        if e1 == e2:
            return "Infinite solutions"
        elif e1[0] == e2[0]:
            return "No solution"
        else:
            return "x=%d" % ((e2[1]-e1[1])//(e1[0]-e2[0]))
```
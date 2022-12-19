这题比较简单，用栈，计算每轮分数入栈，最后求和即可
```
class Solution:
    def calPoints(self, ops: List[str]) -> int:        
        stack = []
        for i in ops:
            if i=="+":
                s= stack[-1]+stack[-2]
                stack.append(s)
            elif i=="D":
                s= stack[-1]*2
                stack.append(s)
            elif i=="C":
                stack.pop()
            else:
                stack.append(int(i))    
        return sum(stack)
```
   
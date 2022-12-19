```
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        stack = []
        l = [0] * len(T)
        
        for i,j in enumerate(T):
            while stack and j > T[stack[-1]]:
                l[stack[-1]] = i - stack[-1]
                stack.pop()
            stack.append(i)
        
        return l
```

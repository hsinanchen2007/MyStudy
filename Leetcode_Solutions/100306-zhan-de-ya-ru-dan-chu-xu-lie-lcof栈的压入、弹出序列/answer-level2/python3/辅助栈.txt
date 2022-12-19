```python
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        if not pushed and not popped: return True
        if not pushed or not popped: return False
        stack = []
        i = j = 0
        while j < len(popped):
            if stack and stack[-1] == popped[j]:
                stack.pop()
                j += 1
            elif i < len(pushed):
                if pushed[i] == popped[j]:
                    j += 1
                    i += 1
                else:
                    stack.append(pushed[i])
                    i += 1
            else: return False
        return True
```
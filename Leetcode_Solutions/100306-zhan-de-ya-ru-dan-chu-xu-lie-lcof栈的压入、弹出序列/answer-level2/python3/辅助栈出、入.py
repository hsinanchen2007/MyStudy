请大佬们指教
```
代码块
class Solution:
    def validateStackSequences(self, pushed, popped) -> bool:
        stack, stack1, i, j = [], [], 0, 0
        if not pushed and not popped:
            return True
        while j < len(popped):
            if i < len(pushed):
                stack.append(pushed[i])
            while stack and stack[-1] == popped[j]:
                stack.pop(-1)
                j += 1
                if not stack and j == len(popped):
                    return True
            if i > len(pushed) and stack[-1] != popped[j]:
                return False
            i += 1
```

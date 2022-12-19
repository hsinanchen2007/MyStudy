```
代码块
class Solution:
    def verifyPostorder(self, postorder) -> bool:
        return self.dfs(postorder[::-1])
    def dfs(self, stack):
        if not stack or len(stack) == 1: return True
        if stack[1] > stack[0]:
            if min(stack[1:]) > stack[0]:
                return self.dfs(stack[1:])
            for i in range(2,len(stack)):
                if stack[i] < stack[0]:
                    if max(stack[i:]) < stack[0]:
                        return self.dfs(stack[1:i]) and self.dfs(stack[i:])
                    else: return False
        if stack[1] < stack[0] and max(stack[1:]) < stack[0]:
            return self.dfs(stack[1:])
        else: return False
```

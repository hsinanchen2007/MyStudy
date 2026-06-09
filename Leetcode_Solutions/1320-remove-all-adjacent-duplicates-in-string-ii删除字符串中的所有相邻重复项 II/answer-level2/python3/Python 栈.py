```python
class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stack = []
        for st in s:
            if len(stack) == 0 or stack[-1][0] != st:
                stack.append((st, 1))
            else:
                top, cnt = stack.pop()
                cnt += 1
                if cnt != k: stack.append((top, cnt))
        return ''.join([item[0] * item[1] for item in stack])
```
时间复杂度 $O(len(s))$ ,空间复杂度$O(len(s))$

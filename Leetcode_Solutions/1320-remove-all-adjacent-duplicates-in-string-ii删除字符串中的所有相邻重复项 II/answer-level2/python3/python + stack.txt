```python
class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        # stack
        # Time complexity : O(N)
        # Space compelxity: O(N)
        stack = []
        for ch in s:
            if not stack or ch != stack[-1][0]:
                stack.append([ch, 1])
            else: stack[-1][1] += 1
            if stack and stack[-1][1] >= k:
                if stack[-1][1] > k:
                    stack[-1][1] -= k
                else: stack.pop()
        return ''.join([ch * cnt for ch, cnt in stack])   
```
```python
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        # stack
        # Time complexity : O(N)
        # Space complexity : O(N) 
        stack = []
        i, j = 0, 0
        while i < len(pushed) and j < len(popped):
            stack.append(pushed[i])
            while stack and stack[-1] == popped[j]:
                stack.pop()
                j += 1
            i += 1
        return stack == []
```
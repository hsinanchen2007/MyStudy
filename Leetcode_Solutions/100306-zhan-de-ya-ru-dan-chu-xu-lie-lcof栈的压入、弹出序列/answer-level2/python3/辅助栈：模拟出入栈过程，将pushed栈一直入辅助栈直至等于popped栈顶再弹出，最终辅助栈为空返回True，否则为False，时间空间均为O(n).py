### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        if not pushed and not popped:
            return True
        if not pushed or not popped:
            return False
        pushed_index, popped_index = 0,0
        stack = []
        while pushed_index < len(pushed):
            stack.append(pushed[pushed_index])
            pushed_index += 1
            while stack and stack[-1] == popped[popped_index]:
                stack.pop()
                popped_index += 1
        if not stack:
            return True
        return False


        
```
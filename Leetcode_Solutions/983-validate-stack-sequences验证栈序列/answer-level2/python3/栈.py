### 解题思路
入栈序列进行入栈操作，栈顶等于出栈序列第一个数就出栈

### 代码

```python3
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack = []
        cur = 0
        for i in range(len(pushed)):
            stack.append(pushed[i])
            while stack and cur < len(popped) and stack[-1] == popped[cur]:
                stack.pop()
                cur+=1
        return False if stack else True
```
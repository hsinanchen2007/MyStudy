### 解题思路

`pop`操作的复杂度是$O(1)$比`pop(0)`的$O(N)$操作要快很多，所以就先反转`popped`了。

### 代码

```python []
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack, popped = [], popped[:: -1]
        for i in pushed:
            stack.append(i)
            while stack and popped[-1] == stack[-1]:
                stack.pop()
                popped.pop()
        return not popped
```
```python []
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack = []
        for i in pushed:
            stack.append(i)
            while stack and popped[0] == stack[-1]:
                stack.pop()
                popped.pop(0)
        return not popped
```
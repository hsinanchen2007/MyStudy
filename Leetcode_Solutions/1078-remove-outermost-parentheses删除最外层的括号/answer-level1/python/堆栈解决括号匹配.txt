### 解题思路
堆栈解决括号匹配

### 代码

```python3
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        stack, flag, count = [], 0, 0
        for i in range(len(S)):
            if flag == 0:
                count, flag = 0, 1
                continue
            if flag == 1 and count == 0 and S[i] == ')':
                flag = 0
                continue
            stack.append(S[i])
            count = count + 1 if S[i] == '(' else count - 1
        return ''.join(stack)

```
### 解题思路
看到括号就用栈，老规矩了

### 代码

```python3
class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        stack = []
        for c in S:
            if c == ')' and stack and stack[-1] == '(':
                stack.pop()
                continue
            stack.append(c)
        return len(stack)

```
欢迎关注的我的[github](https://github.com/tcandzq/LeetCode)，查看更多精彩题解。
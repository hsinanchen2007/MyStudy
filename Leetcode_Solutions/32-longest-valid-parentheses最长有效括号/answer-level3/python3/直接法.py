解题思路用栈匹配括号，存下括号索引，对索引进行排序，计算最长连续的索引

### 代码

```python3
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        count = 1
        max_count = 0
        stack = []
        i_stack = []
        for i,c in enumerate(s):
            if c == '(':
                stack.append([i,c])
            elif c == ')':
                if len(stack) == 0:
                    pass
                elif stack[-1][-1] == '(':
                    old_i,_ = stack.pop()
                    i_stack.append(old_i)
                    i_stack.append(i)
        i_stack.sort()
        for i in range(len(i_stack)-1):
            if i_stack[i]+1 == i_stack[i+1]:
                count +=1
                max_count = max(max_count,count)
            else:
                count = 1
        return max_count
```
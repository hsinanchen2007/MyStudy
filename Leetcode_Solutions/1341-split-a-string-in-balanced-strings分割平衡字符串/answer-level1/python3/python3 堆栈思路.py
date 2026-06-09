### 解题思路
堆栈的思路，笨且低效。

### 代码

```python3
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        counter = 0
        stack = ''
        for c in s:
            if stack == '':
                stack += c 
            elif c == stack[-1]:
                    stack += c 
            else:
                stack = stack[:-1]
                if stack == '':
                    counter += 1
                
        return counter
```
### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        stack = []
        s = []
        for i in str(x):
            stack.insert(0,i)
        while stack:
            s.append(stack.pop(0))
        if s[0] == '0' and len(s)!=1:
            s.pop(0)
        result = ''
        
        if s[len(s)-1] == '-':
            s.pop(len(s)-1)
            for i in s:
                result += i
            result = int(result)
            if result>2**31:
                return(0)
            else:
                return(0-result)
        else:     
            for i in s:
                result += i
            result = int(result)
            if result>2**31:
                return(0)
            else:
                return(result)
```
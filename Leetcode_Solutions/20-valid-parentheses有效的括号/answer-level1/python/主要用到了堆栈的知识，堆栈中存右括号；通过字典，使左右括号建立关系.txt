### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        dic = {")": "(", "}": "{", "]": "["}#用括号引用相应的左括号
        for c in s: 
            if c in dic: #key，c是右括号
                stackpop=stack.pop() if stack else '#'
                if dic[c] != stackpop:
                    return False
            else:
                stack.append(c)
        
        return len(stack)==0
```
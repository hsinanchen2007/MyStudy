### 解题思路
右括号入栈，左括号时看和栈顶是不是同类型。

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        lefts={"(":0,"{":1,"[":2,}
        rights={")":0,"}":1,"]":2}

        stack=[]
        for char in s:
            if char in lefts:
                stack.append(char)
            elif len(stack)==0:
                return False
            else:
                bracket=stack.pop()
                if lefts[bracket]!=rights[char]:
                    return False
        return len(stack)==0
```
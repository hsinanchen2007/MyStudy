### 解题思路
建立两个栈，遇到#就出战栈，最后判断栈是否相等

### 代码

```python3
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        s1=[]
        s2=[]
        for char in S:
            if char=="#":
                if s1:
                    s1.pop()
            else:
                s1.append(char)
        for char in T:
            if char=="#":
                if s2:
                    s2.pop()
            else:
                s2.append(char)
        return s1==s2
        
        
```
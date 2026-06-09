### 解题思路
用了好多判断

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        s_list = []
        left = ['(','[','{']
        right = [')', ']','}']
        for i in range(len(s)):
            if s[i] in left:
                s_list.append(s[i])
            if s[i] in right:
                if s_list == []:
                    return False
                temp = s_list.pop()
                ind = left.index(temp)
                if s[i] != right[ind]:
                    return False
        if s_list != []:
            return False
        
        return True
```
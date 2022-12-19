### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        n = list(s)
        d = []
        r = False
        if len(n) == 0:
            r = True
            return r
        if len(n) == 1:
            r = False
            return r
        for i in range(len(n)):
            if n[i] == "(" or n[i] == "{" or n[i] == "[":
                d.append(n[i])
            if n[i] == ")" and len(d) > 0:
                if d[len(d) - 1] == "(":
                    d.pop()
                else:
                    r = False
                    break
            elif n[i] == ")" and len(d) == 0:
                r = False
                break
            if n[i] == "}" and len(d) > 0:
                if d[len(d) - 1] == "{":
                    d.pop()
                else:
                    r = False
                    break
            elif n[i] == "}" and len(d) == 0:
                r = False
                break
            if n[i] == "]" and len(d) > 0:
                if d[len(d) - 1] == "[":
                    d.pop()
                else:
                    r = False
                    break
            elif n[i] == "]" and len(d) == 0:
                r = False
                break
            if i == len(n) - 1 and len(d) == 0:
                r = True
        return r
```
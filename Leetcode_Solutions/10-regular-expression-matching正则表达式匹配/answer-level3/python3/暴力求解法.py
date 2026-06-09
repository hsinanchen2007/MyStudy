### 解题思路
此处撰写解题思路

如果p[j]的后一位是*，说明在p中 j 和 j+1 这两位是可以不匹配的，那么让后面的p[j + 2：]匹配，p[j + 2：]匹配上则成功；不能匹配上则p[j]根据规则进行匹配，不能匹配上则丢弃这两位继续匹配，能匹配上则继续匹配后面的字符

### 代码

```python3
class Solution:
    def isMatch(self, s: str, p: str) -> bool:

        i = 0
        j = 0

        while i < len(s):
            if j >= len(p):
                return False

            if (j + 1) < len(p) and p[j + 1] == '*':
                if self.isMatch(s[i:], p[j+2:]):
                    return True
                if p[j] != '.' and  p[j] != s[i]:
                    j += 2
                else:
                    i += 1
            elif p[j] == '.' or  p[j] == s[i]:
                i += 1
                j += 1
            else:
                return False

        if j >= len(p):
            return True

        success = True
        for j in range(j, len(p)):
            if p[j] != '*':
                if not success:
                    return False
            success = True if p[j] == '*' else False
        return success
            
        return True
            
```
### 解题思路
挨个遍历超时,后来加上了 长度是part倍数的验证就过了

### 代码

```python
class Solution(object):
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        for i in range(1,len(s)/2+1):
            if len(s)%i:
                continue
            part=s[:i]
            if len([x for x in s.split(part) if x ]):
                # print [x for x in s.split(part) if x ]
                continue
            else:
                return True
        return False
```
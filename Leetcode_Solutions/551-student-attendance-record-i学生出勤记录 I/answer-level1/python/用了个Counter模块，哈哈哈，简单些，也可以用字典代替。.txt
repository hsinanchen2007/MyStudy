### 解题思路
用了个Counter模块，哈哈哈，简单些，也可以用字典代替。

### 代码

```python
class Solution(object):
    from collections import Counter
    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        re=Counter(s)
        lens=len(s)
        if re['A']>=2:
            return False
        for i in range(lens-2):
            if s[i]=='L' and s[i+1]=='L' and s[i+2]=='L':
                return False
                i+=1
        return True
```
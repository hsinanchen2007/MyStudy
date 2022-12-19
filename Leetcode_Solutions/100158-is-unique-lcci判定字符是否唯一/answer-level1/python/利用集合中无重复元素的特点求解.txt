### 解题思路
将字符串转化为集合，如果有重复字符则会被删掉，因此，只要长度变小了，则证明有重复字符。

### 代码

```python
class Solution(object):
    def isUnique(self, astr):
        newset = set(astr)
        if len(newset) < len(astr):
            return False
        else:
            return True
```
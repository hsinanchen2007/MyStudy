### 解题思路
成员运算符解决

### 代码

```python
class Solution(object):
    def isUnique(self, astr):
        """
        :type astr: str
        :rtype: bool
        """
        astr_set=[]
        for item in astr:
            if item not in astr_set:
                astr_set.append(item)
        if len(astr_set)!=len(astr):
            return False
        else:
            return True
```
### 解题思路
直接利用sorted 排序，判断两个字符串排序后是否相等就可以

### 代码

```python3
class Solution(object):
    def CheckPermutation(self,s1,s2):
        """
        
        :param s1: str
        :param s2: str
        :return: bool
        """
        return sorted(list(s1))==sorted(list(s2))
```
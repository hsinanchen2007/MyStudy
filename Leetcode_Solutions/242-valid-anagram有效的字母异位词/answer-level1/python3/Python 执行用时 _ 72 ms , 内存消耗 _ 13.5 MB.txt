### 解题思路
直接使用字典进行比较，元素相等即返回True，否则False，可以忽略顺序。

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        import collections
        s1 = collections.Counter(s)
        s2 = collections.Counter(t)
        
        if s1 == s2:
            return True
        else:
            return False
```
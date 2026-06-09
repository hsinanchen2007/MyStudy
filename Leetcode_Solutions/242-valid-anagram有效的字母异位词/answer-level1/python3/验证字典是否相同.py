
```python
class Solution:
  def isAnagram(self, s: str, t: str) -> bool:
        s_c=collections.Counter(s)
        t_c=collections.Counter(t)
        if s_c!=t_c:
            return False
        else:
            return True
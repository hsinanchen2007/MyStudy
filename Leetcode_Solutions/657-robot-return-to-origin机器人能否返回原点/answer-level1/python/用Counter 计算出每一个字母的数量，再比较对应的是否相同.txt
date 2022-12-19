### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        a = collections.Counter(moves)
        if len(a) == 1 or len(a)==3 or len(a) ==0:
            return False
        if a.setdefault("R") == a.setdefault("L") and a.setdefault("U") == a.setdefault("D"):
            return True
        else:
            return False
```
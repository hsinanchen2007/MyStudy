### 解题思路
如代码所示

### 代码

```python
class Solution(object):
    def minSteps(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        from collections import Counter
        ss=Counter(s)
        tt=Counter(t)
        if ss.items()==tt.items():
            return 0 
        else:
            result=0
            for key,num in ss.items():
                result=result+num-min(num,tt[key])
            return result
```
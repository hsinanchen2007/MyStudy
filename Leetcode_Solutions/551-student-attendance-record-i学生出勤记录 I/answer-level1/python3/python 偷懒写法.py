"""
解题思路：
第一个条件：小于等于一个A，s.count('A') <= a
第二个条件：连续不超过两个L → 只要两个以上L就不可以 → 用 'LLL' 分割，能分割开说明有连续三个或三个以上L，不能分割，没有连续三个L,
len(s.split('LLL')) <= 1
"""

```
class Solution:
    def checkRecord(self, s: str) -> bool:

        s_list = s.split('LLL')
        if len(s_list) <= 1 and s.count('A') <= 1:
            return True
        return False
```



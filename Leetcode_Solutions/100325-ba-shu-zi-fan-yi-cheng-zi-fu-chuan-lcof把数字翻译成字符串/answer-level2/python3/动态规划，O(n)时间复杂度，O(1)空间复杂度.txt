```python
class Solution:
    def translateNum(self, num: int) -> int:
        pre = 1
        pre_pre = 1
        s_num = str(num)
        for i in range(len(s_num)):
            cur = 0
            if 0 <= int(s_num[i]) < 26:
                cur += pre
            if i >= 1 and 10 <= int(s_num[i-1:i+1]) < 26:
                cur += pre_pre
            pre, pre_pre = cur, pre 
        return pre 
```
### 解题思路
正则非常简练，一开始确实没往正则想，一堆if else，参照经典解题写一遍，正则耗时真的低，60ms->36ms

### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        str = str.lstrip()
        s = re.match(r'^[\+\-]?\d+', str)
        print(type(s))
        if s==None:
            return 0
        s = s.group()
        s = int(s)
        return max(min(s,2**31-1), -2**31)

```
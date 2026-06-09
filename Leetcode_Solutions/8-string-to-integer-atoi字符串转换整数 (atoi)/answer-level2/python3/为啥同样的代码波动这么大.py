### 解题思路
此处撰写解题思路
菜鸟一枚求点评，刚学会正则表达式

### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        import re
        s1 = str.strip()
        r1 = re.compile('(\+\d\d*)|(\-\d\d*)|(\d\d*)')
        # num = re.match(r1, s1).group()
        if re.match(r1, s1):
            num = re.match(r1, s1).group()
            if int(num) > 2 ** 31 - 1:
                return 2 ** 31 - 1
            elif int(num) <= - 2 ** 31:
                return - 2 ** 31
            else:
                return int(num)
        else:
            return 0

```
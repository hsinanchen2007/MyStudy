### 解题思路
如果字符串可以转换成数字，那么只可能有两种模式`A[[.[B]][e|EC]]`或`.B[e|EC]`。
+ 其中A、B、C都必须是整数，可以是有符号的，也可以是无符号的；
+ 其中`[]`中的内容可有可无，“可有可无”可以用逻辑运算“或”来判断；





### 代码

```python3
class Solution:
    def isNumber(self, s: str) -> bool:
        s = s.strip(' ')
        if not s:
            return False
        nums = [str(num) for num in range(10)]
        idx = 0

        def is_unsigned_int():
            nonlocal idx
            start = idx
            while idx < len(s) and s[idx] in nums:
                idx += 1
            return idx > start

        def is_int():
            nonlocal idx
            if idx < len(s) and s[idx] in ["+", "-"]:
                idx += 1
            return is_unsigned_int()

        numeric = is_int()
        if idx < len(s) and s[idx] == '.':
            idx += 1
            numeric = is_unsigned_int() or numeric

        if idx < len(s) and s[idx] in ['e', 'E']:
            idx += 1
            numeric = is_int() and numeric

        return numeric and idx == len(s)
```
### 解题思路
1. 先去掉左边的空格符, 然后正则匹配, `'^[\-|\+]?\d+'`
2. 再对匹配的值进行`int`转换, 如果失败返回`0`
3. 最后将结果和`min_int_32`, `max_int32` 比较, 按照题目要求不越界返回结果

### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        import re
        l = re.findall('^[\-|\+]?\d+', str.lstrip())  # 先去掉左边的空格符, 然后正则匹配.
        try:
            res = int(l[0])
        except Exception as e:
            res = 0
        min_int_32, max_int32 = -(1 << 31), (1 << 31) -1
        # 将res和max_int32比较取出较小的值, 然后将这个值和min_int_32比较出较大的值
        return max(min(max_int32, res), min_int_32)
```
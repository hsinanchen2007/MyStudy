### 解题思路
看到这道题第一个思路就是正则，可能是之前爬虫的时候用正则太频繁了。依据大神的思路修改了最后一行，击败了93。

### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        import re
        re_str = r"\s*[-|+]?\d+"
        result = re.match(re_str, str)
        try:
            result = int(result[0].strip(" "))
        except:
            return 0
        else:
            return max(min(result, 2**31 - 1), (-2)**31)
```
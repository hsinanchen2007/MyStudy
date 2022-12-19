### 解题思路
使用python内置`collections.Counter()`（高性能容量数据类型）
字符串长度：`len(str)`
Counter用法：https://blog.csdn.net/qwe1257/article/details/83272340
### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        cnt = collections.Counter(s)
        res = 0
        for i in cnt.values():
            if i%2 == 0:
                res += i
            else:
                res += i-1
        return res+(res<len(s))

```
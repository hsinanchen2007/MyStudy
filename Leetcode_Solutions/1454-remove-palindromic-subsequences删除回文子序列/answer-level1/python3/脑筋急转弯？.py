### 解题思路
1. 如果为空，结果为0
2. 如果字符串本身就是回文字符串，删除一次即可。
3. 因为是删除子序列，而不是连续的子串，只要先删除所有的a，再删除所有的b即可，因此删除两次即可。

tips：
s[::-1] s的反序列

### 代码

```
class Solution:
    def removePalindromeSub(self, s: str) -> int:
        if not s:
            return 0
        if s == s[::-1]:
            return 1
        else:
            return 2
```
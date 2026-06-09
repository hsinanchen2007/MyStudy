### 解题思路
这题其实只有三种情况：
空白返还0
回文返还1
否则先删掉a再删掉b只需要两次(注意子序列的定义)

### 代码

```python3
class Solution:
    def removePalindromeSub(self, s: str) -> int:
        if len(s) == 0:
            return 0
        elif s[::-1] == s:
            return 1
        else:
            return 2

```
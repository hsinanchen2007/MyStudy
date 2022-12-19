执行用时 :40 ms, 在所有 Python3 提交中击败了99.04% 的用户。
内存消耗 :13.2 MB, 在所有 Python3 提交中击败了64.82%的用。

```
class Solution:
    def isUgly(self, num: int) -> bool:
        if num:
            while num % 5 == 0:
                num = num // 5
            while num % 3 == 0:
                num = num // 3
            while num % 2 == 0:
                num = num // 2
        return num == 1
```

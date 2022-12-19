### 解题思路
我说怎么越写越别扭，原来是题目考我高中语文呢
### 代码

```python3
class Solution:
    def removePalindromeSub(self, s: str) -> int:
        if s == "":
            return 0
        elif s[:] == s[::-1]:
            return 1
        else:
            return 2

```
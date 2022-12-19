### 解题思路
[~i] 表示倒数第i个元素

### 代码

```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """

        if not s:
            return []

        for i in range(len(s)//2):
            s[i], s[~i] = s[~i], s[i]

        return s


```
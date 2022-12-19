### 解题思路
这还要解释吗. 傻子都会!

### 代码

```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        len_s = len(s)
        for i in range(len_s // 2):
            s[len_s - 1 - i], s[i] = s[i], s[len_s - 1 - i]
```
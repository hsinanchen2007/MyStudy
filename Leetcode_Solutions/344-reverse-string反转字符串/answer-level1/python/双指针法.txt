### 解题思路
双指针法反转字符串

### 代码

```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        p1, p2 = 0, len(s) - 1
        for i in range(0, len(s) // 2):
            s[p1], s[p2] = s[p2], s[p1]
            p1, p2 = p1 + 1, p2 - 1
```
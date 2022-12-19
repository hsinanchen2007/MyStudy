### 解题思路
利用 global_ptr 索引长度为 2k 的子串，在子串内利用双指针进行翻转。

### 代码

```python3
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        s, slen = list(s), len(s)

        for global_ptr in range(0, slen, 2 * k):
            left = global_ptr
            right = min(left + k - 1, slen - 1)
            while left < right:
                s[right], s[left] = s[left], s[right]
                left += 1
                right -= 1

        return ''.join(s)
```
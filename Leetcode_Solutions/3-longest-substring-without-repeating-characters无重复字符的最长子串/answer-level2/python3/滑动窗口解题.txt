### 解题思路
    遍历字符串  元素依次加入窗口
    先进行判断在不在窗口中
    如果遍历的字符在窗口中，则将窗口的依次左边移除直到没有相同的字符  abca -> abc pww -> w

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s: return 0
        left = 0
        lookup = set()
        n = len(s)
        max_len = 0
        cur_len = 0
        for i in range(n):
            cur_len += 1
            while s[i] in lookup:   #当前遍历的字符在窗口当中
                lookup.remove(s[left])
                left += 1
                cur_len -= 1
            if cur_len > max_len: max_len = cur_len
            lookup.add(s[i])
        return max_len
```
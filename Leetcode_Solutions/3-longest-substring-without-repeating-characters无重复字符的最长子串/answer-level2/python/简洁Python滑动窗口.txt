### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        from collections import defaultdict
        left = 0
        right = 0
        res = 0
        window = defaultdict(int)
        
        while right < len(s):
            c1 = s[right]
            window[c1] += 1
            right += 1
            # 如果 window 中出现重复字符,开始移动 left 缩小窗口
            while window[c1] > 1:
                c2 = s[left]
                window[c2] -= 1
                left += 1
            res = max(res, right - left)
        return res
```
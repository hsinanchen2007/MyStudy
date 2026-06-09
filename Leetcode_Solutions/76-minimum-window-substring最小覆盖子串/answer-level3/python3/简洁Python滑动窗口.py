### 代码

```python3
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        from collections import defaultdict
        min_len = float('inf')
        start = 0
        left = 0
        right = 0
        # 相当于两个计数器
        needs = defaultdict(int)
        window = defaultdict(int)
        # 记录 window 中已经有多少字符符合要求了
        match = 0
        for c in t:
            needs[c] += 1
        while right < len(s):
            c1 = s[right]
            if c1 in needs:
                window[c1] += 1
                if window[c1] == needs[c1]:
                    # 字符 c1 的出现次数符合要求了
                    match += 1
            right += 1
            # window 中的字符串已符合 needs 的要求了
            while match == len(needs):
                if right - left < min_len:
                    start = left
                    min_len = right - left
                c2 = s[left]
                if c2 in needs:
                    window[c2] -= 1 # 移出 window
                    if window[c2] < needs[c2]:
                        # 字符 c2 出现次数不再符合要求
                        match -= 1
                left += 1
        if min_len != float('inf'):
            return s[start:start + min_len]
        else:
            return ""
```
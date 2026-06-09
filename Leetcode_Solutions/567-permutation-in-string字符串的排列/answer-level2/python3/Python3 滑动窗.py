### 解题思路
1. 固定一个和S1一样长度的窗口，在S2中不断滑动窗口

2. 滑动过程用哈希表存储内容，每次滑动都删去原来窗口中的第一个字符并添加下一个新的字符

### 代码

```python3
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2): return False
        if not s1: return True
        n = len(s1)
        needs, windows = {}, {}
        for s in s1:
            needs[s] = needs.get(s, 0) + 1
        for i in range(n-1):
            windows[s2[i]] = windows.get(s2[i], 0) + 1
        for i in range(len(s2) - n + 1):
            # print(windows, needs)
            windows[s2[i+n-1]] = windows.get(s2[i+n-1], 0) + 1
            if windows == needs:
                return True
            else:
                windows[s2[i]] -= 1
                if windows[s2[i]] == 0:
                    windows.pop(s2[i])
        return False
```
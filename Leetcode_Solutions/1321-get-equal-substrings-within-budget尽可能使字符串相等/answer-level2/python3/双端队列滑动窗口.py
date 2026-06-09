-   双端队列滑动窗口
-   滑动窗口使用双端队列实现
-   保存窗口的损失
    -   如果当前损失大于最大损失，清空窗口
    -   如果当前损失加上窗口损失大于总损失，将窗口左侧损失弹出，直到损失小于等于最大损失为止



```python
from collections import deque


class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        windows = deque()
        ans = 0
        cost = 0
        for x, y in zip(s, t):
            diff = abs(ord(x) - ord(y))
            if diff > maxCost:
                cost = 0
                windows.clear()
                continue
            while cost + diff > maxCost:
                cost -= windows.popleft()

            cost += diff
            windows.append(diff)
            ans = max(ans, len(windows))

        return ans
```



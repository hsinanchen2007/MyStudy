![image.png](https://pic.leetcode-cn.com/d0852a3decd6219f5cd863ed24d3f9ffb7368a59ed27eb47259c2b359cd51e1c-image.png)

48ms，仅供参考。

```python []
class Solution:
    def largeGroupPositions(self, S: str) -> List[List[int]]:
        ans, p, t = [], 0, ''       #初始化t为当前字符
        for i, c in enumerate(S):
            if c != t:
                if i - p >= 3:
                    ans += [[p, i - 1]]
                p, t = i, c         #修改当前字符，记录该字符的首次出现坐标
        if len(S) - p >= 3:         #尾处理
            ans += [[p, len(S) - 1]]
        return ans
```

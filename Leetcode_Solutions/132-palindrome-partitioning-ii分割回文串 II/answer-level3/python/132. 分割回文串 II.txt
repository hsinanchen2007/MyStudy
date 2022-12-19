### 代码

```python3
# 缓存以加快速度
import functools
class Solution:
    @functools.lru_cache(None)
    def minCut(self, s: str) -> int:
        if s == s[::-1]: # 若本身已为回文串，则无需分割；
            return 0
        ans = float('inf')
        for i in range(1, len(s)):
            if s[:i] == s[:i][::-1]: # 若当前为回文串
                ans = min(self.minCut(s[i:]) + 1, ans) # 计算后续字符需要切割多少次，加现在的一次， 更新最少切割次数；
        return ans

  

```
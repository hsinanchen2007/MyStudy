偷懒过关，好孩子千万别学~

```python []
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if re.fullmatch(p,s):
            return True
        return False
```

![Python-懒人过关.png](https://pic.leetcode-cn.com/170e0ba41313cd095b44e9f8057bdaad0dfa3c04d0a15df45e090c2cff15ca71-Python-%E6%87%92%E4%BA%BA%E8%BF%87%E5%85%B3.png)


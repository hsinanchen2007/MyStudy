一个结论:
动态规划是更高效的“缓存”；
所以：
```python
class Solution:
    def numDecodings(self, s: str) -> int:
        cache = {}

        def helper(remain):
            if remain in cache:
                return cache[remain]

            if len(remain) == 0:
                return 1
            
            count = 0
            # fetch one char
            if 0 < int(remain[0]) < 10:
                count += helper(remain[1:])
            # fetch two chars
            if 10 <= int(remain[:2]) <= 26:
                count += helper(remain[2:])
            
            cache[remain] = count
            return count
        
        return helper(s)
```

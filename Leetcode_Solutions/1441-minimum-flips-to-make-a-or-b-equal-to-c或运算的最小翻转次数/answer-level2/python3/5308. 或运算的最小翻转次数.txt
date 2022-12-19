
```python []
class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        ans = 0
        while a or b or c:
            (a, x), (b, y), (c, z) = divmod(a, 2), divmod(b, 2), divmod(c, 2)
            ans += ((x | y) ^ z) + (x & y & ~ z)
        return ans
```

![image.png](https://pic.leetcode-cn.com/6de98d1a49df40a56b6e3d8099a350e1a063cd16189a06d71621ee2aadc28e4c-image.png)

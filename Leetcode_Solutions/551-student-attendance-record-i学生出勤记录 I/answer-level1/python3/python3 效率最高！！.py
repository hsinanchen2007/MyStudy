![image.png](https://pic.leetcode-cn.com/ec0aca8817accabbc3a616e6161a41e136b3953a86c3916b60135fa931025f51-image.png)

```
class Solution:
    def checkRecord(self, s: str) -> bool:
        return s.count("A")<=1 and not "LLL" in s
```

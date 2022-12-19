![image.png](https://pic.leetcode-cn.com/2a3ceea2efe944e912e36c37a73f67fda0645edd95b6b9b3d68b0c0dabe92c00-image.png)


```
class Solution:
    def isNumber(self, s: str) -> bool:
        try:
            val = float(s)
            return True
        except Exception:
            return False
```

![image.png](https://pic.leetcode-cn.com/aea1a969392e9b1191dab6dd91739f4ea9b1586f55a4ad34c3b5c3976ab33a86-image.png)


```
class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        try:
            num = float(s)
        except:
            return False
        return True

```


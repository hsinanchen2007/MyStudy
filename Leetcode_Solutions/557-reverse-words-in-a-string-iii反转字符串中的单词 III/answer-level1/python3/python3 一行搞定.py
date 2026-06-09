![image.png](https://pic.leetcode-cn.com/71056b5bf1e772e564096c35c338f307ffe10c69da45f9e6f8a72314c9289cf7-image.png)

```
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join([w[::-1] for w in s.split()])
```

![image.png](https://pic.leetcode-cn.com/10c7b93ff2e1717a80251f73f1eb6fae3a38ad84352c3624c1d3b3821b227e2d-image.png)

### 解题思路
判断每个字母出现次数是否相等，不等判错，反之最后相等判对。

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):return False
        se = set(s)
        for i in se:
            if s.count(i) != t.count(i):return False
        return True
```
### 解题思路
python的正则表达式#

### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        import re
        matches=re.match('([+-]?\d+)',str.lstrip())
        if not matches:
            return 0
        return min(max(int(matches[0]), -2**31), 2**31-1)
  




```
![Snipaste_2020-04-07_15-54-04.png](https://pic.leetcode-cn.com/77fcedda9a22b9a6fa53f5cf18c93ee3ed2d88922b4409a22c7ed82f6876bc39-Snipaste_2020-04-07_15-54-04.png)


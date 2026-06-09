### 解题思路
官方思路的优化。

### 代码

```python3
class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0]=="0":
            return 0
        pre, cur = 1, 1
        for i in range(1, len(s)):
            if s[i] == "0":
                if s[i-1] in "12":
                    cur = pre
                else:
                    return 0
            else:
                if s[i-1] == "1" or s[i-1] == "2" and s[i] in "123456":
                    pre, cur = cur, cur + pre
                else:
                    pre = cur

        return cur


```
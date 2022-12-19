### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numDecodings(self, s: str) -> int:
        if int(s[0]) == 0:
            return 0

        pre = 1
        curr = 1

        for i in range(1, len(s)):
            tmp = curr
            x = int(s[i - 1])
            y = int(s[i])

            if y == 0:
                if (x == 1 or x == 2):
                    curr = pre
                else:
                    return 0
            elif x * 10 + y <= 26 and x != 0:
                curr += pre
            
            pre = tmp



        return curr

```
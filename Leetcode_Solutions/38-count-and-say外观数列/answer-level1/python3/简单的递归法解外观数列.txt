### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        else:
            res = ""
            count = 0
            s = self.countAndSay(n-1)
            for i in range(len(s)):
                if i == 0 or s[i] == s[i-1]:
                    count += 1
                else:
                    res += str(count) + s[i-1]
                    count = 1
            res += str(count) + s[i]
            return res 
```
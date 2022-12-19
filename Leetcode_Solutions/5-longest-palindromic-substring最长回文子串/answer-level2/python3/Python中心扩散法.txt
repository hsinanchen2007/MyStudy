### 解题思路
中心扩散法，分别探索目标串为奇数长度和偶数长度，以及偶数长度时左侧长和右侧长的情况。

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        count, max_, ret, now = 0, 0, "", ""
        for i in range(len(s)):
            temp, count, now = min(i, len(s) - i - 1), 1, "".join(s[i])
            for j in range(1, temp + 1):
                if s[i - j] == s[i + j]:
                    count += 2
                    now = "".join(s[i - j]) + now + "".join(s[i + j])
                else:
                    break
            if count > max_:
                max_, ret = count, now
            count ,now = 0, ""
            if i < len(s) - i - 1:
                for j in range(0, temp + 1):
                    if s[i - j] == s[i + j + 1]:
                        count += 2
                        now = "".join(s[i - j]) + now + "".join(s[i + j + 1])
                    else:
                        break
            elif i > len(s) - i - 1:
                for j in range(0, temp + 1):
                    if s[i - j - 1] == s[i + j]:
                        count += 2
                        now = "".join(s[i - j - 1]) + now + "".join(s[i + j])
                    else:
                        break
            if count > max_:
                max_, ret = count, now
        return ret
```
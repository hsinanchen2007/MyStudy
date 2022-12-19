
```python []
class Solution:
    def freqAlphabets(self, s: str) -> str:
        ans, i = '', len(s) - 1
        while i >= 0:
            if s[i] == '#':
                ans += chr(int(s[i - 2: i]) + 96)
                i -= 3
            else:
                ans += chr(int(s[i]) + 96)
                i -= 1
        return ans[:: -1]
```

![image.png](https://pic.leetcode-cn.com/457bea95e6464e0e5d74356a0b735b59bf8b56b57b840a71fd3f596ee02bccb6-image.png)

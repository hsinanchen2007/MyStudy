模拟的窗口模式

```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        if s == '':
            return 0
        win_size=1
        x=0
        while x+win_size<=len(s):
            if x+win_size<=len(s) and set(s[x:x+win_size]).__len__() == s[x:x+win_size].__len__():
                win_size+=1
            else:
                x+=1
        return win_size-1
```
### 解题思路
解法很简单，满足条件的回文串一定要顶左边。所以我们从左往右每次对半折开看是不是回文，注意分开单双的处理。找到最长的回文串后把右边剩下的翻转贴到前面就完了。

### 代码

```python3
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        N = len(s)
        if N < 2 : return s
        res = 0
        for i in range(1,N):
            m = (i+1)//2
            if s[:m] == s[m if (i+1)%2==0 else m+1:i+1][::-1] : res = i
        return s[res+1:][::-1]+s
```
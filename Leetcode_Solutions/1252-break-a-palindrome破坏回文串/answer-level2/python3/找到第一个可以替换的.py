### 解题思路
只要找到第一个可以替换的字符，替换成'a'就成了
满足下面两个条件的不能被替换：
1. 字母是a，本身已经最小了，不能被替换
2. 字符串长度是奇数，那么中间的字符不能被替换，因为不管怎么换，最后字符串还是palindrome

### 代码

```python3
class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        for i, ch in enumerate(palindrome):
            if ch != 'a' and (not len(palindrome)&1 or i != len(palindrome)//2):
                return palindrome[:i]+'a'+palindrome[i+1:]
        return "" if len(palindrome) == 1 else palindrome[:-1] + 'b'
```
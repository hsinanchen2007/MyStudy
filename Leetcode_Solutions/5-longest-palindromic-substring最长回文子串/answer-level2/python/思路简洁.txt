### 解题思路
从单个字符开始，向右匹配与之相等的字符，然后比对左右两边的字符是否相等，从字符串的第一个字符开始，比对到最后一个字符即可

### 代码

```python3
class Solution:
    def __init__(self):
        self.maxLength = 1;
        self.maxStr = ''
    def checkLength(self, s, index):
        first = index-1;
        last = index+1;
        count = 1;
        sameFlag = True;
        while sameFlag and last<len(s) :
            if s[index] == s[last]:
                count += 1;
                if self.maxLength < count:
                    self.maxLength = count
                    self.maxStr = s[index:last+1]
                last += 1;
            else:
                sameFlag = False;
        while first>=0 and last<len(s):
            if s[first] == s[last]:
                count += 2;
                if self.maxLength < count:
                    self.maxLength = count
                    self.maxStr = s[first:last+1]
                first += -1;
                last += 1;
            else:
                return
    def longestPalindrome(self, s: str) -> str:
        if len(s)==0:
            return ''
        self.maxStr = s[0]
        for i,v in enumerate(s):
            self.checkLength(s, i)
        return self.maxStr
```
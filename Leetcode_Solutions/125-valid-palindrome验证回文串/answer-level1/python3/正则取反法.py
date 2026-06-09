先将输入正则化，提取字母和数字，然后与反向比对
``` Python
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        s = re.sub(u"([^\u4e00-\u9fa5\u0030-\u0039\u0041-\u005a\u0061-\u007a])", "", s)
        # print(s)
        if s == s[::-1]:
            return True
        else:
            return False
```

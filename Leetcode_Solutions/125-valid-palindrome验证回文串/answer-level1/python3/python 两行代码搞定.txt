![捕获.JPG](https://pic.leetcode-cn.com/069a7953c4c0e4c3e57c87c1e09cd434a5ebf2036795a75bffa0029c9f1fb799-%E6%8D%95%E8%8E%B7.JPG)
```
class Solution:
    def isPalindrome(self, s: str) -> bool:
        import re
        s=re.sub("[^a-zA-Z0-9]","",s).lower()
        return s==s[::-1]
```


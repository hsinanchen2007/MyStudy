### 解题思路
利用回文的对称性，两边出现的字母次数加起来是偶数，中间可以再加一个字母

### 代码

```python3
from collections import Counter
class Solution:
    def longestPalindrome(self, s: str) -> int:
        dict01=Counter(s)
        res=0
        for v in dict01.values():
            res+=v//2*2
            if res%2==0 and v%2:
                res+=1
        return res 
```
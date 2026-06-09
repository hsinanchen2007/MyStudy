### 解题思路
不多考虑，凡是偶数个全加上，奇数那就加上最大的偶数，最后根据是否有奇数判断加一

### 代码

```python3
import collections
class Solution:
    def longestPalindrome(self, s: str) -> int:
        dic=collections.Counter(s)
        length=0
        maximum=0
        for i in dic.values():
            if i%2==0:
                length+=i
            else:
                length+=i-1
                maximum=1
        return length+maximum
```
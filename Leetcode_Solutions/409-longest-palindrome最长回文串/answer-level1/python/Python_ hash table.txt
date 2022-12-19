### 解题思路
不是最优的O(n)，不过很好理解

### 代码

```python
class Solution:
    def longestPalindrome(self, s: str) -> int:
        dic = {c: 0 for c in set(s)}
        res = 0
        for c in s:
            dic[c] +=1
            if dic[c] >=2:
                dic[c] -=2
                res +=2
        return res+1 if any(dic.values()) else res
```
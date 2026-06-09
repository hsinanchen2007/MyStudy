### 解题思路
1.使用Counter统计每个字母出现的次数
2.若为偶数，直接加
3.若为奇数，减1再加，最后再加上1（使用flag）。

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        from collections import Counter
        HT=Counter(s)
        res=0
        flag=False
        for key in HT:
            if HT[key]%2==0:res+=HT[key]
            else:
                res+=HT[key]-1
                flag=True
        res+=flag
        return res
```
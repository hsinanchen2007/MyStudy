### 解题思路
记录每个字符个数。

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        dic = {}
        count1 = 0
        count2 = 0
        for i in range(len(s)):
            dic[s[i]] = dic.get(s[i],0) + 1
        for value in dic.values():
            if value == 1:
                count1 += 1
            if value > 1:
                count2 += value//2
                if value%2 == 1:
                    count1 += 1
        return count2*2 + 1 if count1 > 0 else count2*2
                
```
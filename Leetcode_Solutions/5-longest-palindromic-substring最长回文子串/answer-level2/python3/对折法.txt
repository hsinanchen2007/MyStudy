### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        length = len(s)
        Max0 = 1
        location = 0
        for i in range(length):
            pre = i - 1
            after = i + 1
            Max = 1
            while pre > -1 and after < length and s[pre] == s[after]:
                print(s[pre], s[after])
                Max += 2
                pre -= 1
                after += 1
            if Max > Max0:
                Max0 = Max
                location = i
            pre = i    #第二种情况
            after = i+1
            Max = 0 
            while pre > -1 and after < length and s[pre] == s[after]:
                Max += 2
                pre -= 1
                after += 1
            if Max > Max0:
                Max0 = Max
                location = i
                
        if Max0 % 2 == 0:
            return s[location - Max0//2 +1 : location + Max0//2+1]
        else :
            return s[location - Max0//2 : location + Max0//2+1]        
```
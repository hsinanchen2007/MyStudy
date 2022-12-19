### 解题思路
用类似递归的思想，不断取循环，改变s中的值。

### 代码

```

class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        ##用类似递归的思想来做
        i = 0 
        while i < len(s)-1:
            if s[i:i+k] == s[i]*k:  ##这样的写法更高效
                s = s[:i]+s[i+k:] 
                # print(s)
                i = 0
            else:
                i+=1
        return s

```
```
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        
        #附更相减损求x,y的最大公因数
        #def helper(x, y):
        #    if x == y:
        #        return x 
        #    x, y = max(x,y), min(x,y)
        #    return (y, x-y)

        def helper(s1, s2):
            if s1 == s2:
                return s1
            if len(s1) < len(s2):
                s1, s2 = s2, s1  
            l = len(s2)
            for i in range(1, l+1):
                if s1[-i] != s2[-i]:
                    return ''
            return helper(s1[:-l], s2)
        return helper(str1, str2)
```


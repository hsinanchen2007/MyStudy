```
class Solution:
    def compress(self, chars: List[str]) -> int:
        if len(chars)<=1:
            return len(chars)
        i = 0
        num = 1
        chars += chr(10)
        for j in range(1, len(chars)):
            if chars[j-1] == chars[j]:
                num += 1
            else:
                i += 1
                if num>1:
                    s = str(num)
                    for k in range(len(s)):
                        chars[i] = s[k]
                        i += 1
                chars[i] = chars[j]      
                num = 1
        return i
```

解法二
```
class Solution:
    def compress(self, chars: List[str]) -> int:
        if len(chars)<=1:
            return len(chars)
        i = 0
        f = 0
        for j in range(len(chars)):
            if j==len(chars)-1 or chars[j+1] != chars[j]:
                chars[i] = chars[f]      
                i += 1
                if j>f:
                    for s in str(j-f+1):
                        chars[i] = s
                        i += 1
                f = j + 1
        return i
```

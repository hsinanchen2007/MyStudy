

两次翻转
整体翻转后对每个单词翻转

```
class Solution:
    def reverseWords(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        s.reverse()
        i = 0
        j = 0
        while j <= len(s):
            if j == len(s) or s[j] == ' ':
                temp = j-1
                while i<=temp:
                    s[i],s[temp] = s[temp],s[i]
                    i,temp = i+1,temp-1
                i = j+1
            j+=1
        return s
```


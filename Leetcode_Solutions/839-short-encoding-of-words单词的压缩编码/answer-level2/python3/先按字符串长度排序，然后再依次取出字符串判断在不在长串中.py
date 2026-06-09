```
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words = sorted(words,key=lambda i:len(i),reverse=True)
        temp = ""
        for i in words:
            this_strs = i+"#"
            if this_strs not in temp:
                temp+=this_strs
        return len(temp)
```



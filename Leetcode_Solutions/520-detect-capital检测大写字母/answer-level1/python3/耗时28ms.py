```
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        str1 = word.upper()
        str2 = word.lower()
        n1 = len(word)
        if word == str1 or word == str2:
            return(True)
        elif n1 > 1:
            word1 = word[0:1]
            word2 = word1.upper()
            word3 = word[1:]
            word4 = word3.lower()
            if word1 == word2 and word3 == word4:
                return(True)
            else:
                return(False)
        else:
            return(False)
            
```

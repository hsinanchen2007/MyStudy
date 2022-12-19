```
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        char_list=[0]*26
        for char in chars:
            char_list[ord(char)-ord("a")]+=1
        res=0
        for word in words:
            charList=char_list.copy()
            for i in range(len(word)):
                if charList[ord(word[i])-ord("a")]:
                    charList[ord(word[i])-ord("a")]-=1
                else:
                    break
                if i==len(word)-1:
                    res+=len(word)
        return res

```
